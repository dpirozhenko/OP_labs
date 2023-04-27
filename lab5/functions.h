#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip> 

using namespace std;

#pragma once

class Event {
private:
    tm date;
    int time;

public:

    Event();

    Event(int y_ear, int m_onth, int d_ay, int t_ime);

    int getTime();

    void printDate();

    virtual void info() = 0;

    void time_left(int given);
};

class Meeting : public Event {
private:
    string name;
    string place;

public:

    Meeting();

    Meeting(string n_ame, string p_lace, int year, int month, int day, int t_ime);

    void info();

};

class Birthday : public Event {
private:
    string name;
    string place;
    int age;

public:
    Birthday();

    Birthday(string n_ame, string p_lace, int a_ge, int year, int month, int day, int t_ime);

    void info();
};

bool check_date(int, int, int);
void show_meetings(Meeting*, int);
void sort_meetings(Meeting*, int);
void create_meetings(Meeting*, int, int, int, int);
Birthday create_b(int, int, int);
int add_meeting(Meeting*, int, int, int, int);
Birthday create_birthday(int, int, int);
void show_schedule(Meeting*, Birthday&, int);
void menu(Meeting*, int, int, int, int);
void create_schedule(Meeting*);

