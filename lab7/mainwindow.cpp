#include "mainwindow.h"
#include "binaryfile.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QMessageBox>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
   
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *fileInputLayout = new QHBoxLayout();
    QLabel *inputLabel = new QLabel("Введіть вміст початкового файлу:", this);
    QTextEdit *inputTextEdit = new QTextEdit(this); // Заміна QLineEdit на QTextEdit
    fileInputLayout->addWidget(inputLabel);
    fileInputLayout->addWidget(inputTextEdit);
    inputTextEdit->setStyleSheet("background-color: #FFF6F6");


    QGridLayout *boundAndMultLayout = new QGridLayout();
    QLabel *rangeLabel = new QLabel("Введіть діапазон:", this);
    QLabel *lowLabel = new QLabel("Від:", this);
    QLabel *highLabel = new QLabel("До:", this);
    QLabel *multLabel = new QLabel("Введіть множник:", this);
    QLineEdit *lowLine = new QLineEdit(this);
    QLineEdit *highLine = new QLineEdit(this);
    QLineEdit *multLine = new QLineEdit(this);

    boundAndMultLayout->addWidget(rangeLabel, 0, 0);
    boundAndMultLayout->addWidget(lowLabel, 1, 0);
    boundAndMultLayout->addWidget(highLabel, 2, 0);
    boundAndMultLayout->addWidget(multLabel, 3, 0);
    boundAndMultLayout->addWidget(lowLine, 1, 1);
    boundAndMultLayout->addWidget(highLine, 2, 1);
    boundAndMultLayout->addWidget(multLine, 3, 1);
    lowLine->setStyleSheet("background-color: #FFF6F6");
    highLine->setStyleSheet("background-color: #FFF6F6");
    multLine->setStyleSheet("background-color: #FFF6F6");
 
    QPushButton *processButton = new QPushButton("Обробити файл", this);
    processButton->setStyleSheet("background-color: #FFB9B5");

    QTextEdit *outputTextEdit = new QTextEdit(this);
    outputTextEdit->setReadOnly(true);
    outputTextEdit->setStyleSheet("background-color: #FFF6F6");


    mainLayout->setSpacing(20);
    mainLayout->addLayout(fileInputLayout);
    mainLayout->addLayout(boundAndMultLayout);
    mainLayout->addWidget(processButton);
    mainLayout->addWidget(outputTextEdit);
    setCentralWidget(centralWidget);
    setStyleSheet("background-color: #FFDCDA");

    connect(processButton, &QPushButton::clicked, this, [inputTextEdit, lowLine, highLine, multLine, outputTextEdit]() {
        try {
            QString inputText = inputTextEdit->toPlainText();
            BinaryFile binaryFile(inputText.toStdString(),"input.bin");
            string l_bound = lowLine->text().toStdString();
            string h_bound = highLine->text().toStdString();
            validateBoundaries(l_bound, h_bound);
            int low = stoi(l_bound);
            int high = stoi(h_bound);

            string mult_str = multLine->text().toStdString();
            validateMult(mult_str);
            int mult = stoi(mult_str);

            BinaryFile processedFile = binaryFile.process( low, high, mult, "processed.bin");

            outputTextEdit->setText("Вміст нового файлу:\n");
            outputTextEdit->append(QString::fromStdString(processedFile.printNumbers()));

        }
        catch (const exception& e) {
            QMessageBox::critical(nullptr, "Помилка", QString("Упс... Виникла помилка") + e.what());
        }
    });
}

MainWindow::~MainWindow()
{
}
