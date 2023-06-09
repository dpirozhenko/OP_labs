#ifndef BINARYFILE_H
#define BINARYFILE_H

#include <QMainWindow>

using namespace std;


class BinaryFile
{
    string file_name;
    int size;
public:
    BinaryFile(string nums_text, string name);
    BinaryFile(const int* nums_arr, int numsSize, string name);
    BinaryFile process(int high, int low, int mult, string name);
    string printNumbers();
};

bool validateBoundaries(string low, string high);
bool validateMult(string mult);

#endif // BINARYFILE_H
