#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"


int main() {

    Meeting* meetings = new Meeting[100];
    int n, day, month, year, choice;
    string ddate;
    bool flag1 = true;
    bool flag2 = true;

    do {
        cout << "\n1-> create schedule automaticaly\n2-> write your schedule\n3-> finish the program " << endl;
        cin >> choice;

        if (choice == 1) {
            create_schedule(meetings);
        }
        else if (choice == 2) {
            do {
                cout << "At first lets create some meetings \nEnter number (up to 10): " << endl;
                cin >> n;
                cout << "Enter the date (dd.mm.yy): " << endl;
                cin.ignore();
                getline(cin, ddate);
                sscanf(ddate.c_str(), "%d.%d.%d", &day, &month, &year);

                if (check_date(year, month, day)) {
                    create_meetings(meetings, n, year, month, day);
                    cout << "List of meetings:" << endl;
                    sort_meetings(meetings, n);
                    show_meetings(meetings, n);
                    flag2 = false;
                }
                else {
                    cout << "The date is incorrect. Try again...";
                }

            } while (flag2);

            menu(meetings, n, year, month, day);

            flag1 = false;

        }
        else if (choice == 3) {
            cout << "Bye!";
            flag1 = false;
        }
        else {
            cout << "Something went wrong...Try again";
        }

    } while (flag1);

}
