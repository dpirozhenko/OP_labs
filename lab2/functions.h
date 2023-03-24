#include <iostream>
#include <fstream>
#include <cstring> 
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

#pragma once

class Client {
public:
    char surname[100];
    int t_in;
    int t_out;
    int hour1;
    int minute1;
    int hour2;
    int minute2;

    Client();
    Client(std::string _surname, int _t_in, int _t_out);


    int timein() const;
    int timeout() const;

    void info();


};

void create(Client, std::string);
bool compare_by_time(const Client&, const Client&);
void read(std::string);
void clients_to_file(const std::vector<Client>&, std::string);
void input(const std::vector<Client>&);
int check_time(const std::vector<Client>&, int);
int check_timeout(const std::vector<Client>&, int, int);
int to_minutes(int, int);
void breaks(const std::vector<Client>&);
