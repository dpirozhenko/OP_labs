#include "streammode.h"


void generate_data(std::string filename, int mode) {
    std::cout << "Enter the text: ";

    std::string line;
    std::string text = {0};

    if (mode == 0) {
        std::ofstream myFile(filename);

        while (true) {
            std::getline(std::cin, text);
            if (text[0] == '\0') break;
            myFile << text << std::endl;
        }

        myFile.close();

    }
    else if (mode == 1) {
        std::ofstream myFile(filename, std::ios::app);
        std::cin.ignore();

        while (true) {
            std::getline(std::cin, text);
            if (text[0] == '\0') break;
            myFile << text << std::endl;
        }

        myFile.close();
    }
}


void read_file(std::string filename) {
    std::fstream myFile;

    myFile.open(filename, std::ios::in);

    if (myFile.is_open()) {
        std::string line;
        while (getline(myFile, line)) {
            std::cout << line << std::endl;
        }
        myFile.close();
    }

}



int count_odd_words(std::string line) {
    int count = 0;
    int wordLength = 0;
    for (char c : line) {
        if (isalpha(c)) {
            wordLength++;
        }
        else {
            if (wordLength % 2 == 1) {
                count++;
            }
            wordLength = 0;
        }
    }
    if (wordLength % 2 == 1) {
        count++;
    }
    return count;
}


void strings(std::string filename) {

    std::ifstream myFile(filename);
    std::ofstream outFile("output.txt");
    
    std::string line;
    int num = 0;
    char c;

    while (getline(myFile, line)) {
        num++;

        if (num % 2 == 0) {
            std::string a = "";
            std::string b = "";
            for (int i = 0; i < line.length(); i++) {
                c = line[i];
                if (i % 2 != 0) {
                    a += c;
                }
                else {
                    b += c;
                }
            }
            std::string new_line = b + a;
            outFile << new_line << ", " << count_odd_words(new_line) << std::endl;
        }
    }
    myFile.close();
    outFile.close();
}


void streammode(std::string filename, int mode){

    generate_data(filename, mode);
    std::cout << "\nInput file:\n";
    read_file(filename);
    strings(filename);
    std::cout << "\n\nOutput file:\n";
    read_file("output.txt");
}
