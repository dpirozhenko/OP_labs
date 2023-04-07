#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"

int MAX_EMPLOYEES = 100;

int main() {

    Employee* employees = new Employee[MAX_EMPLOYEES];
    bool flag = true;
    int choice;
    int n = 0;
    cout << "This program creates an array of employees and you can find the employee with the longest work experience" << endl;

    do {
        cout << "\nMENU:\n1) - add an employee\n2) - find an employee with the longest work experience\n3) - finish the program " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:

            add_employees(employees, n);
            n++;
            break;
        case 2:

            experience(employees, n);
            break;
        case 3:

            cout << "Bye!" << endl;
            flag = false;
            break;
        default:

            cout << "You`ve entered wrong symbol...Try again" << endl;
            break;
        }

    } while (flag);

    delete[]employees;


}
