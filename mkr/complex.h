#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

#pragma once

class TComplex {
public:
	int Re, lm;
public:
	TComplex(int x, int y) : Re(x), lm(y){}
	void print(string);
	TComplex operator++();

};

void read_file(string);
void find_obj(TComplex, TComplex, string);
