#pragma once

#include <iostream>

using namespace std;


template <typename KeyType, typename ValueType>
class Node {
public:
    KeyType key;
    ValueType value;
    bool used;

    Node() : used(false) {}
};

template <typename KeyType, typename ValueType>
class HashTable {
private:
    int size;
    Node<KeyType, ValueType>* table;
    unsigned int MurmurHash2(const KeyType* key, int len, int seed);
    int hashFunction(const KeyType& key);

public:

    HashTable(int size);
    ~HashTable();

    void insert(const KeyType& key, const ValueType& value);
    void remove(const KeyType& key);
    bool isEmpty() const;
    int get_size();

    class Iterator {
    private:
        const HashTable<KeyType, ValueType>& hashTable;
        int currentIndex;

    public:
        Iterator(const HashTable<KeyType, ValueType>& hashTable, int index);

        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        Iterator& operator++();
        const Node<KeyType, ValueType>& operator*() const;
    };

    Iterator begin() const;
    Iterator end() const;
};

