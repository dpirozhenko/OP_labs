#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"


Event::Event() {
        date = { 0 };
        time = 0;
    }

Event::Event(int y_ear, int m_onth, int d_ay, int t_ime) {
        date.tm_year = y_ear;
        date.tm_mon = m_onth;
        date.tm_mday = d_ay;
        time = t_ime;
    }

    int Event::getYear() { return date.tm_year; }

    int Event::getMonth() { return date.tm_mon; }

    int Event::getDay() { return date.tm_mday; }

    int Event::getTime() { return time; }

    void Event::printDate() {
        cout << setw(3) << date.tm_mday << "." << date.tm_mon << "." << date.tm_year;
    }


    void Event::Event::time_left(int given) {
        int t = time - given;
        int hour = t / 60;
        int min = t % 60;

        cout << "\nTime gap:";

        if (min < 10) {
            cout << setw(4) << hour << "hours 0" << min << " minutes" << endl;
        }
        else {
            cout << setw(4) << hour << "hours " << min << " minutes" << endl;
        }
    }




Meeting::Meeting() {
        name = "";
        place = "";
    }

Meeting::Meeting(string n_ame, string p_lace, int year, int month, int day, int t_ime) : Event(year, month, day, t_ime) {
        name = n_ame;
        place = p_lace;
    }

    void Meeting::info() {
        int t1 = this->getTime() / 60;
        int t2 = this->getTime() % 60;
        this->printDate();              //наче мило а наче і хуйня 
        if (t2 < 10) {
            cout << setw(4) << t1 << ":0" << t2;
        }
        else {
            cout << setw(4) << t1 << ":" << t2;
        }

        cout << " - " << name << " at the " << place << endl;
    }




Birthday::Birthday() {
        name = "";
        place = "";
        age = 0;
    }

Birthday::Birthday(string n_ame, string p_lace, int a_ge, int year, int month, int day, int t_ime) : Event(year, month, day, t_ime) {
        name = n_ame;
        place = p_lace;
        age = a_ge;
    }

    void Birthday::info() {
        int t1 = this->getTime() / 60;
        int t2 = this->getTime() % 60;
        this->printDate();
        if (t2 < 10) {
            cout << setw(4) << t1 << ":0" << t2;
        }
        else {
            cout << setw(4) << t1 << ":" << t2;
        }

        cout << " - " << "Celebration of " << name << "'s " << age << " Birthday at the " << place << endl;
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

void show_meetings(Meeting* meetings, int n) {

    for (int i = 0; i < n; i++) {
        meetings[i].info();
    }
}

void sort_meetings(Meeting* meetings, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (meetings[j].getTime() > meetings[j + 1].getTime()) {
                Meeting temp = meetings[j];
                meetings[j] = meetings[j + 1];
                meetings[j + 1] = temp;
            }
        }
    }
}

void create_meetings(Meeting* meetings, int n, int y, int m, int d) {

    string names[10] = { "John", "Sarah", "Michael", "Emily", "David", "Olivia", "James", "Emma", "Alexander", "Sophia" };
    string meetingPlaces[10] = { "Coffee Shop", "Library", "Park", "Museum", "Restaurant", "Beach", "Shopping Mall", "Movie Theater", "Gym", "Art Gallery" };
    int i = 0;
    srand(time(NULL));

    for (i; i < n; i++) {

        int k = 0 + rand() % 10;
        int time = 540 + rand() % (1020 - 540 + 1);
        meetings[i] = Meeting(names[i], meetingPlaces[k], y, m, d, time);

    }
}

Birthday create_b(int y, int m, int d) {

    string names[10] = { "Alice", "Bob", "Charlie", "David", "Emily", "Frank", "Gina", "Harry", "Isabel", "Nick"};
    string places[] = { "Beach", "Park", "Restaurant", "Movie theater", "Bowling alley", "Amusement park", "Zoo", "Museum", "Skating rink", "Game center" };

    srand(time(NULL));

    int k = 0 + rand() % 10;
    int time = 1021 + rand() % (1200 - 1020 + 1);
    int age = 10 + rand() % (30 - 10 + 1);
    Birthday b(names[k], places[k], age, y, m, d, time);

    return b;
}

int add_meeting(Meeting* meetings, int n, int y, int m, int d) {
    bool flag = true;
    string name, place, ttime;
    int hour, min, a;

    do {

        cout << "\nEnter name of the penson you want to meet: ";
        cin >> name;
        cout << "Enter place of the meeting: ";
        cin >> place;
        cout << "Enter time of the meeting (hh:mm): ";
        cin.ignore();
        getline(cin, ttime);
        sscanf(ttime.c_str(), "%d:%d", &hour, &min);
        int h = (hour * 60) + min;

        meetings[n] = Meeting(name, place, y, m, d, h);
        meetings[n].info();
        n++;

        cout << "Do you want to add more?[1 - yes | 2 - no]: ";
        cin >> a;
        if (a == 2) {
            flag = false;
        }

    } while (flag);

    return n;
}

Birthday create_birthday(int y, int m, int d) {
    string name, place, ttime;
    int hour, min, age;

    cout << "\nEnter name of the penson whose Birthday you're want to attend: ";
    cin >> name;
    cout << "\nEnter their age: ";
    cin >> age;
    cout << "Enter place of the meeting: ";
    cin >> place;
    cout << "Enter time of the meeting (hh:mm): ";
    cin.ignore();
    getline(cin, ttime);
    sscanf(ttime.c_str(), "%d:%d", &hour, &min);

    int h = (hour * 60) + min;
    Birthday c(name, place, age, y, m, d, h);

    return c;
}

void show_schedule(Meeting* meetings, Birthday& b, int n) {


    cout << "Schedule: " << endl;
    sort_meetings(meetings, n);
    show_meetings(meetings, n);
    b.info();

    int t = meetings[n - 1].getTime();
    b.time_left(t);

}

void menu(Meeting* meetings, int n, int y, int m, int d) {
    int choice;
    bool flag = true;
    Birthday b;
    int k = 0;
    do {
        cout << "\n1-> add meeting\n2-> add Birthday\n3-> show schedule\n4-> finish the program  " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            n = add_meeting(meetings, n, y, m, d);
            sort_meetings(meetings, n);
            cout << "New list of meetings:" << endl;
            show_meetings(meetings, n);
            break;

        case 2:

            b = create_birthday(y, m, d);

            break;

        case 3:
            show_schedule(meetings, b, n);
            break;
        case 4:
            cout << "byee!!" << endl;
            flag = false;
            break;
        default:
            cout << "You've entered wrong symbol...Try again";
            break;

        }

    } while (flag);

}

void create_schedule(Meeting* meetings) {
    int n;
    cout << "Enter number of meetings (up to 10): " << endl;
    cin >> n;
    srand(time(NULL));
    int year = 2000 + rand() % (2050 - 2000 + 1);
    int month = 1 + rand() % (12 - 1 + 1);
    int day = 1 + rand() % (28 - 1 + 1);
    create_meetings(meetings, n, year, month, day);
    Birthday b = create_b(year, month, day);

    show_schedule(meetings, b, n);

}
