#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"


int main() {

    int choice, check;
    bool flag = true;

    do {
        cout << "Lets create three vectors: " << endl;

        Line b1 = create_vector();
        Line b2 = create_vector();
        Line b3 = create_vector();

        if (b1 || b2) {
            cout << "\nLines b1 and b2 are parallel.\n";
        }
        else {
            cout << "\nLines b1 and b2  are not parallel.\n";
        }

        ++b3;
        //b3.info();
        cout << "New coordinates of the begginang for b3 are: (" << b3.getX1() << "; " << b3.getY1() << ")" << endl;

        b3.count_lenght();
        cout << "\nDo you want to recreate lines?\n1 -> yes\n2 -> no\n";
        cin >> check;
        if (check == 2) {
            flag = false;
            cout << "\nBye!!!";
        }


    } while (flag);


}
