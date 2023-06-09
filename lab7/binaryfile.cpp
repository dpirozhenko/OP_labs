#include "binaryfile.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

class empty_array : public std::exception {
    string message_;
public:
    empty_array(const string& message) : message_(message) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }
};

class open_file : public std::exception {
    string message_;
public:
    open_file(const string& message) : message_(message) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }
};

bool validate_negative(string element){

    if (element[0]!='-'){
        string err_message = "\nНе можна вводити додатні числа";
        throw invalid_argument(err_message);
    }
    if(element.length()<2){
        string err_message = "\nНекоректно введене значення";
        throw invalid_argument(err_message);
    }
    for (int i=1; i<element.length();i++){
        if(!isdigit(element[i])){
            string err_message;
            if (element[i]==' '){
                err_message = "\nВведено: "+element+"\nНе можна вводити більше одного числа";
            }else{
                err_message = "\nВведено: "+element+"\nМістить символи";
            }
            throw invalid_argument(err_message);
        }
    }
    if(stoll(element)<numeric_limits<int>::min()){
        string err_message = "\nInteger underflow\n"+element+" перевищує допустиму межу";
        throw underflow_error(err_message);
    }
    return true;
}

bool validateBoundaries(string low, string high){
    validate_negative(low);
    validate_negative(high);
    if(stoi(low)>=stoi(high)){
        string err_message = "\nНевірно вказаний діапазон.\nВи маєте вказати діапазон ВІД меншого числа ДО більшого";
        throw invalid_argument(err_message);
    }

    return true;
}

bool validateMult(string mult){
    if(mult[0]=='-'){

        string err_message = "\nВведено: "+mult+"\nНе можна вводити від'ємні числа";
        throw invalid_argument(err_message);
    }
    for (int i=0; i<mult.length();i++){
        if(!isdigit(mult[i])){
            string err_message;
            if (mult[i]==' '){
                err_message = "\nВведено: "+mult+"\nНе можна вводити більше одного числа";
            }else{
                err_message = "\nВведено: "+mult+"\nМістить символи";
            }
            throw invalid_argument(err_message);
        }
    }
    if(stoll(mult)>numeric_limits<int>::max()){
        string err_message = "Integer overflow\n"+mult+" перевищує допустиму межу";
        throw overflow_error(err_message);
    }
    return true;
}

BinaryFile::BinaryFile(string nums_text, string name):file_name(name)
{
    string element;

    for (size_t i = 0; i < nums_text.length(); i++) {
        if (nums_text[i] == '\n') {
            nums_text[i] = ' ';
        }
    }

    size = 0;
    int* nums = new int[size];
    stringstream stream(nums_text);

    while(getline(stream,element,' ')){
        if(validate_negative(element)){
            size += 1;
            int* newArr = new int[size];
            for (int i=0;i<size-1;i++){
                newArr[i]=nums[i];
            }
            delete[] nums;
            nums = newArr;
            nums[size-1] = stoi(element);
        }
    }
    ofstream file(file_name, std::ios::binary);
    if (!file) {
        throw open_file("Не вдолося створити вихідний файл.");
    }

    file.write(reinterpret_cast<const char*>(nums), size * sizeof(int));
    delete[] nums;
    file.close();
}

BinaryFile::BinaryFile(const int* nums, int numsSize, string name):file_name(name),size(numsSize){
    ofstream file(file_name, std::ios::binary);
    if (!file) {
        throw open_file("\nНе вдолося створити вихідний файл.");
    }

    file.write(reinterpret_cast<const char*>(nums), size * sizeof(int));
    file.close();
}


string BinaryFile::printNumbers(){
    string file_content = "";
    ifstream file(file_name, std::ios::binary);
    if (!file) {
        throw open_file("\nНе вдолося створити вихідний файл.");
    }

    int num;
    for(int i = 0; i < size; i++){
        file.read((char *) &num, sizeof(int));
        file_content+=to_string(num)+" ";
    }
    file.close();
    return file_content;
}

BinaryFile BinaryFile::process(int low, int high, int mult, string name){
    int* processedNumbers = new int[size];
    int processedSize = 0;

    ifstream file(file_name, std::ios::binary);
    if (!file) {
        throw open_file("\nНе вдолося створити вихідний файл.");
    }

    int current_num;
    for (int i=0;i<size;i++){
        file.read((char *) &current_num, sizeof(int));
        if(current_num>=low && current_num<=high){
            int num_x_mult = current_num*mult;
            if(current_num < numeric_limits<int>::min()/mult){
                delete[] processedNumbers;
                file.close();
                string err_message = "\nInteger underflow\n"+to_string(current_num)+" перевищує допустиму межу";
                throw underflow_error(err_message);
            }
            processedNumbers[processedSize++]=num_x_mult;
        }
    }

    file.close();
    if(processedSize==0){
        delete[] processedNumbers;
        throw empty_array("\nНемає елементів, що задовільняють умову.");
    }

    BinaryFile processedFile(processedNumbers, processedSize, name);
    delete[] processedNumbers;
    return processedFile;
}
