#include "complex.h"

int main() {

	TComplex objA(11, 2), objB(1, 4);
	std::ofstream Myfile;
	Myfile.open("file.txt", ios::out);


	objA.print("file.txt");
	objB.print("file.txt");


	find_obj(objA, objB, "file.txt");

	read_file("file.txt");
	
	
	Myfile.close();



}
