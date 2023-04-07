#include <iostream>
#include <string>

using namespace std;

#pragma once


class Employee {
private:
    string name;
    int year;
    int month;
    int date;

public:

    Employee();

    Employee(string n_name, int y_ear, int m_onth, int d_ate);

    int get_year();

    int get_month();

    int get_date();

    void info();

    void exp_info(int iyear);

};


bool check_date(int, int, int);
void add_employees(Employee*, int);
void find_employee(Employee*, int, int);
void show_employees(Employee*, int);
void experience(Employee*, int);
