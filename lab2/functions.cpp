#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"



Client::Client() {}
Client::Client(std::string _surname, int _t_in, int _t_out) {
    strcpy(surname, _surname.c_str());
    t_in = _t_in;
    t_out = _t_out;
    hour1 = _t_in / 60;
    minute1 = _t_in % 60;
    hour2 = _t_out / 60;
    minute2 = _t_out % 60;
}


int Client::timein() const { return t_in; }
int Client::timeout() const { return t_out; }

void Client::info() {
    std::cout << "Surname: " << surname << "\tFrom " << hour1 << ":" << minute1 << "\t to " << hour2 << ":" << minute2 << std::endl;
}


void create(Client obj, std::string filename) {//запис ОБ'ЄКТІВ у файл
    std::ofstream f(filename, std::ios::binary | std::ios::app);
    f.write((char*)&obj, sizeof(obj));
    f.close();
}

bool compare_by_time(const Client& a, const Client& b) {
    return a.timein() < b.timein();
}

void read(std::string filename) {
    std::ifstream f(filename, std::ios::binary);//читання ОБ'ЄКТІВ з файлу
    Client obj;

    while (f.read((char*)&obj, sizeof(obj))) {
        obj.info();
    }
    f.close();
}

void clients_to_file(const std::vector<Client>& clients, std::string filename) {
    std::string surname;
    int time1;
    int time2;

    for (const auto& client : clients) {
        surname = client.surname;
        time1 = client.t_in;
        time2 = client.t_out;
        Client a(surname, time1, time2);
        create(a, filename);
    }
}


int check_time(const std::vector<Client>& clients, int time) {
    int count = 0;
    for (const auto& client : clients) {
        if (time >= client.t_in && time <= client.t_out) {
            count = 1;
        }

    }
    return count;
}

int check_timeout(const std::vector<Client>& clients, int timeout, int timein) {
    int count = 0;

    for (const auto& client : clients) {
        if ((timein < client.t_in && timeout > client.t_in) || (timein < client.t_out && timeout > client.t_out)) {
            count = 1;
            break;
        }
        else {
            count = 0;

        }
    }

    return count;
}

int to_minutes(int hour, int minute) {
    int time = hour * 60 + minute;
    return time;

}


void breaks(const std::vector<Client>& clients) {
    std::cout << "Breaks that manager had during a day:\n";
    int count = 1;
    int from[100];
    int to[100];
    int i = 1;
    int j = 0;
    bool nine = true;
    bool five = true;
    for (const auto& client : clients) {
        if (client.t_in != 540) {
            from[0] = 540;
            nine = false;
        }
        else if (client.t_in == 540) {
            from[0] = client.t_out;
            nine = true;
        }

        if (client.t_out != 1020) {
            to[j] = 1020;
        }

        from[i] = client.t_out;


        to[j] = client.t_in;
        i++;
        j++;
    }
    bool first = true;
    if (nine) {
        std::cout << "Breaks before 12PM:" << std::endl;
        for (int n = 1; n < i - 1; n++) {
            int hour1 = from[n] / 60;
            int hour2 = to[n] / 60;
            int minute1 = from[n] % 60;
            int minute2 = to[n] % 60;
            if (from[n] > 720 && first) {
                std::cout << "Breaks after 12PM:" << std::endl;
                first = false;
            }
            std::cout << "Gap" << (n + 1) << "\tFrom " << hour1 << ":" << minute1 << "\tto " << hour2 << ":" << minute2 << "\n";

        }
    }
    std::cout << "Breaks before 12PM:" << std::endl;
    for (int n = 0; n < i-1; n++) {
        
        int hour1 = from[n] / 60;
        int hour2 = to[n] / 60;
        int minute1 = from[n] % 60;
        int minute2 = to[n] % 60;
        if (from[n] > 720 && first) {
            std::cout << "Breaks after 12PM:" << std::endl;
            first = false;
        }
        std::cout << "Gap" << (n + 1) << "\tFrom " << hour1 << ":" << minute1 << "\tto " << hour2 << ":" << minute2 << "\n";

    }



}
