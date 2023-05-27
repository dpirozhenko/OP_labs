#include <iostream>

#pragma once

using namespace std;

template <typename KeyType, typename ValueType>
void insert_element(HashTable<KeyType, ValueType>&);

template <typename KeyType, typename ValueType>
void delete_element(HashTable<KeyType, ValueType>&);

template <typename KeyType, typename ValueType>
void print(HashTable<KeyType, ValueType>&);

template <typename KeyType, typename ValueType>
void check_empty(HashTable<KeyType, ValueType>&);

template <typename KeyType, typename ValueType>
void what_size(HashTable<KeyType, ValueType>&);

template <typename KeyType, typename ValueType>
void menu(HashTable<KeyType, ValueType>&);

void type(int);
