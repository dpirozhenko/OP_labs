#include "HsTable.h"
#include "functions.h"


template <typename KeyType, typename ValueType>
void insert_element(HashTable<KeyType, ValueType>& hashTable) {
    KeyType key;
    ValueType value;

    cout << "Enter key: ";
    cin >> key;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');                             // Ігноруємо решту рядка після введення ключа

    cout << "Enter value: ";
    cin >> value;

    hashTable.insert(key, value);
}

template <typename KeyType, typename ValueType>
void delete_element(HashTable<KeyType, ValueType>& hashTable) {
    KeyType key;

    cout << "Enter key of the element you want to delete: ";
    cin >> key;

    hashTable.remove(key);
    cout << "Element was deleted" << endl;

}

template <typename KeyType, typename ValueType>
void print(HashTable<KeyType, ValueType>& hashTable) {

    for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {

        const auto& entry = *it;

        cout << "Key: " << entry.key << ", Value: " << entry.value << endl;

    }
}

template <typename KeyType, typename ValueType>
void check_empty(HashTable<KeyType, ValueType>& hashTable)
{
    if (hashTable.isEmpty()) {
        cout << "The hash table is empty now" << endl;
    }
    else {
        cout << "The hash table is not empty" << endl;
    }

}

template <typename KeyType, typename ValueType>
void what_size(HashTable<KeyType, ValueType>& hashTable) {
    cout << "The size of the hash table is " << hashTable.get_size() << endl;
}

template <typename KeyType, typename ValueType>
void menu(HashTable<KeyType, ValueType>& hashTable) {
    int choice;
    bool flag = true;

    do {
        cout << std::endl << "MENU:" << endl;
        cout << "1-> insert an element" << endl;
        cout << "2-> delete an element" << endl;
        cout << "3-> check if the table is empty" << endl;
        cout << "4-> get size of the table" << endl;
        cout << "5-> print hash table" << endl;
        cout << "6-> exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert_element(hashTable);
            break;
        case 2:
            delete_element(hashTable);
            break;
        case 3:
            check_empty(hashTable);
            break;
        case 4:
            what_size(hashTable);
            break;
        case 5:
            print(hashTable);
            break;
        case 6:
            flag = false;
        default:
            break;
        }


    } while (flag);
}


void type(int size) {

    int choice;

    cout << "Now lets choose the type for the key and the value of the container: " << endl;
    cout << "1-> key - int, value - int " << endl;
    cout << "2-> key - int, value - double " << endl;
    cout << "3-> key - int, value - string " << endl;
    cout << "4-> key - double, value - int " << endl;
    cout << "5-> key - double, value - double " << endl;
    cout << "6-> key - double, value - string " << endl;
    cout << "7-> key - string , value - int " << endl;
    cout << "8-> key - string , value - double " << endl;
    cout << "9-> key - string , value - string  " << endl;

    cin >> choice;

    if (choice == 1) {
        HashTable<int, int> hashTable(size);
        menu(hashTable);
    }
    else if (choice == 2) {
        HashTable<int, double> hashTable(size);
        menu(hashTable);
    }
    else if (choice == 3) {
        HashTable<int, string> hashTable(size);
        menu(hashTable);
    }
    else if (choice == 4) {
        HashTable<double, int> hashTable(size);
        menu(hashTable);
    }
    else if (choice == 5) {
        HashTable<double, double> hashTable(size);
        menu(hashTable);
    }
    else if (choice == 6) {
        HashTable<double, string> hashTable(size);
        menu(hashTable);
    }
    else if (choice == 7) {
        HashTable<string, int> hashTable(size);
        menu(hashTable);
    }
    else if (choice == 8) {
        HashTable<string, double> hashTable(size);
        menu(hashTable);
    }
    else if (choice == 9) {
        HashTable<string, string> hashTable(size);
        menu(hashTable);
    }

}
