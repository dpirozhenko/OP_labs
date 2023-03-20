#include <iostream>
#include <fstream>
#include <string>
#include "pointermode.h"
#include "streammode.h"

using namespace std;

int main(int argc, char* argv[]) {

	if (argc != 2) {
		cout << "Wrong number of arguments: enter name of the program and mode";
		exit(0);
	}

	if (strcmp(argv[1], "-FileStream") == 0) {

		string filename;
		cout << "Enter the name of the file: \n";
		getline(cin, filename);
		streammode(filename, 0);
		int mode;
		bool check = true;
		do {
			cout << "\nIf you want to append to file enter '0', if not enter '1': ";
			cin >> mode;
			if (mode == 0) {
				streammode(filename, 1);
			}
			else {
				check = false;
			}
		} while (check);
		

	}
	else if(strcmp(argv[1], "-FilePointer") == 0) {
		const char* filename = enter_filename();
		pointermode(filename);
		int mode;
		bool check = true;
		do {
			cout << "\nIf you want to append to file enter '0', if not enter '1': ";
			cin >> mode;
			if (mode == 0) {
				pointermode(filename);
			}
			else {
				check = false;
			}
		} while (check);
	}
	else {
		cout << "You've entered wrong arguments.";
		exit(0);
	}
}
