#include "complex.h"

using namespace std;

void TComplex::print(string s) {
	std::fstream Myfile;
	Myfile.open(s, std::ios::app);

	Myfile << "number =" << setw(5) << Re << "." << lm << "\n";
	Myfile.close();
}

TComplex TComplex::operator++() {
	++Re; 
	return *this;
}

void find_obj(TComplex objA, TComplex objB, string s) {
	std::fstream Myfile;
	Myfile.open(s, std::ios::app);

	Myfile << "Incremented bigger ";
	Myfile.close();
	if (objA.Re > objB.Re) {
		++objA;
		objA.print("file.txt");
	}
	else if (objA.Re == objB.Re && objA.lm > objB.lm) {
		++objA;
		objA.print("file.txt");
	}
	else if (objA.Re < objB.Re) {
		++objB;
		objB.print("file.txt");
	}
	else if (objA.Re == objB.Re && objA.lm < objB.lm) {
		++objB;
		objB.print("file.txt");
	}

	

}


void read_file(std::string filename) {
	std::fstream myFile;

	myFile.open(filename, std::ios::in);

	if (myFile.is_open()) {
		std::string line;
		while (getline(myFile, line)) {
			std::cout << line << std::endl;
		}
		myFile.close();
	}

}
