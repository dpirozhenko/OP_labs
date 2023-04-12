#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

Line::Line() : x1(0), y1(0), x2(0), y2(0) {}

Line::Line(double x__2, double y__2) : x1(0), y1(0), x2(x__2), y2(y__2) {}

Line::Line(double x_1, double y_1, double x_2, double y_2) : x1(x_1), y1(y_1), x2(x_2), y2(y_2) {}

double Line::getX1() { return x1; }
double Line::getY1() { return y1; }
double Line::getX2() { return x2; }
double Line::getY2() { return y2; }

//метод обчислення довжини відрізка
void Line::count_lenght() {
    double lenght = 0;
    lenght = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    cout << "Lenght of this line is " << lenght << endl;
}

//перевантажений оператор ++
Line& Line::operator ++() {
    cout << "Incrementing by 1..." << endl;
    this->x1++;
    this->y1++;

    return *this;

}

//перевантажений оператор ||
bool Line::operator||(const Line& other) {

    double a = (y2 - y1) / (x2 - x1);
    double b = (other.y2 - other.y1) / (other.x2 - other.x1);

    return (a == b);
}

//виведення інформації про об'єкт
void Line::info() {
    cout << "The beginning of this line at point (" << x1 << "; " << y1 << ") and end at point (" << x2 << "; " << y2 << ")" << endl;
}


Line create_two_points() {

    double x2, y2, x1, y1;
    string input;

    cout << "Enter the koordinates of the beginnig(x y): ";
    cin.ignore();
    getline(cin, input);

    sscanf(input.c_str(), "%lf %lf", &x1, &y1);
    cout << "Enter the koordinates of the end(x y): ";
    getline(cin, input);
    sscanf(input.c_str(), "%lf %lf", &x2, &y2);

    Line b(x1, y1, x2, y2);
    cout << "Line is created succesfully " << endl;
    b.info();

    return b;

}

Line create_one_point() {

    double x1, y1, x2, y2;
    string input;

    cout << "Enter the koordinates of the end(x y): ";
    cin.ignore();
    getline(cin, input);
    sscanf(input.c_str(), "%lf %lf", &x2, &y2);

    Line b(x2, y2);
    cout << "Line is created succesfully " << endl;
    b.info();

    return b;

}

Line create_vector() {
    int choice;
    cout << "\n1-> enter two points\n2-> enter only an end (begining at (0; 0)) " << endl;
    cin >> choice;

    Line b;
    if (choice == 1) {
        b = create_two_points();
    }
    else if (choice == 2) {
        b = create_one_point();
    }
    else {
        cout << "ohhhhhhhhhh no";
    }

    return b;

}
