#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring> 
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include "functions.h"


using namespace std;


int main() {

    std::vector<Client> clients;
    string input_time;
    string surname;
    string filename;
    ofstream f(filename, ios::binary);
    int hours, minutes;
    int time1, time2;
    int mode;
    bool check = true;
    cout << "This program creates a database of cliens and displayes a manager`s schedule" << endl;
    cout << "Enter the name of binary file you want to create:" << endl;
    std::getline(cin, filename);

    cout << "Lets create the list of the clients: " << endl;
    do {
        cout << "If you want to add a client enter '0' if you want to see manager`s schedule enter '1'if you want to quit enter '2': ";
        cin >> mode;

        if (mode == 0) {
            cout << "Enter a surname ";
            cin >> surname;
            bool flag = true;
            do {

                cout << "Enter time in using format HH:MM: ";
                cin >> input_time;
                sscanf_s(input_time.c_str(), "%d:%d", &hours, &minutes);
                time1 = to_minutes(hours, minutes);
                if (time1 < 540 || time1 > 1020) {
                    cout << "Working hours are from 9:00 to 17:00" << endl;
                }
                else if ((check_time(clients, time1) == 0)) {
                    flag = false;
                }
                else if (check_time(clients, time1) == 1) {
                    cout << "This time is already taken. Try enter time in again..." << endl;
                }

            } while (flag);
            do {
                flag = true;
                cout << "Enter time out using format HH:MM: ";
                cin >> input_time;
                sscanf_s(input_time.c_str(), "%d:%d", &hours, &minutes);
                time2 = to_minutes(hours, minutes);
                int fuck = check_timeout(clients, time2, time1);

                if (time2 < 540 || time2 > 1020) {
                    cout << "Working hours are from 9:00 to 17:00" << endl;
                }
                else if (time2 <= time1) {
                    cout << "Time out cannot be less than or eaqual time in. Try enter time out again..." << endl;
                }
                else if (fuck == 1) {
                    cout << "NO no no don`t do this. Try enter time out again..." << endl;
                }
                else if (check_time(clients, time2) == 1) {
                    cout << "This time is already taken. Try enter time out again..." << endl;
                }
                else if ((check_time(clients, time2) == 0)) {
                    flag = false;
                }

            } while (flag);

            clients.emplace_back(surname, time1, time2);


        }
        else if (mode == 1) {
            std::sort(clients.begin(), clients.end(), compare_by_time);
            clients_to_file(clients, filename);
            cout << "Content of file " << filename << endl;
            read(filename);

            breaks(clients);

            f.close();

            remove(filename.c_str());
        }
        else if (mode == 2) {
            check = false;
        }
        else {
            cout << "You've entered wrong number. Try again..." << endl;
        }

    } while (check);

    return 0;
}
