#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

Employee::Employee() {
    name = "";
    year = month = date = 0;
}

Employee::Employee(string n_name, int y_ear, int m_onth, int d_ate) {
    name = n_name;
    year = y_ear;
    month = m_onth;
    date = d_ate;
}


int Employee::get_year() { return year; }

int Employee::get_month() { return month; }

int Employee::get_date() { return date; }

void Employee::info() {
    cout << name << " started working on " << date << "." << month << "." << year << endl;
}

void Employee::exp_info(int iyear) {
    int y = iyear - year;

    cout << "\nEmployee with the largest working experience is " << name << ", who started working on " << date << "." << month << "." << year << endl;
    cout << "And has workig experience of " << y << " years " << endl;

}



bool check_date(int y, int m, int d) {
    bool flag = true;
    int lp = 0;

    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1) {
        flag = false;
    }
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        flag = false;
    }

    if ((y % 4 == 0) && (y % 100 != 0) || (y % 100 == 0) && (y % 400 == 0)) {
        lp = 1;
    }
    if (m == 2) {
        if (lp == 1 && d > 29) {
            flag = false;
        }
        else if (lp != 1 && d > 28) {
            flag = false;
        }
    }

    return flag;


}

void add_employees(Employee* employees, int num) {
    string namee, input;
    int yyear, mmonth, ddate;
    bool flag = true;

    cout << "\nEnter the name of the employee: ";
    cin.ignore();
    getline(cin, namee);

    do {

        cout << "Enter the date when they started working (dd.mm.yy): ";
        getline(cin, input);
        sscanf(input.c_str(), "%d.%d.%d", &ddate, &mmonth, &yyear);

        if (check_date(yyear, mmonth, ddate)) {
            flag = false;
        }
        else {
            cout << "The date is incorrect. Try again...";
        }

    } while (flag);


    employees[num] = Employee(namee, yyear, mmonth, ddate);

}


void find_employee(Employee* employees, int y, int num) {

    int pos = 0 ;

    for (int i = 1; i < num; i++) {


        if (employees[i].get_year() < employees[0].get_year()) {
            pos = i;
        }
        else if (employees[i].get_year() == employees[0].get_year() && employees[0].get_month() < employees[0].get_month()) {

            pos = i;
        }
        else if (employees[i].get_year() == employees[0].get_year() && employees[i].get_month() == employees[0].get_month() && employees[i].get_date() < employees[0].get_date()) {

            pos = i;
        }
    }

    employees[pos].exp_info(y);

}

void show_employees(Employee* employees, int num) {
    cout << "\nList of employees:" << endl;

    for (int i = 0; i < num; i++) {
        employees[i].info();
    }

}

void experience(Employee* employees, int n) {
    int date, month, year;
    string ddate;
    bool flag = true;

    do {
        cout << "Enter the date to which you want to count experienxe (dd.mm.yy): " << endl;
        cin.ignore();
        getline(cin, ddate);
        sscanf(ddate.c_str(), "%d.%d.%d", &date, &month, &year);

        if (check_date(year, month, date)) {
            flag = false;
        }
        else {
            cout << "The date is incorrect. Try again...";
        }
    } while (flag);

    show_employees(employees, n);
    find_employee(employees, year, n);
}
