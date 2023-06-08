#include "HsTable.h"

template<typename KeyType, typename ValueType>
unsigned int HashTable<KeyType, ValueType>::MurmurHash2(const KeyType* key, int len, int seed) {
    const unsigned int m = 0x5bd1e995;
    const int r = 24;

    unsigned int h = seed ^ len;

    const unsigned char* data = (const unsigned char*)key;

    while (len >= 4) {
        unsigned int k = *(unsigned int*)data;

        k *= m;
        k ^= k >> r;
        k *= m;

        h *= m;
        h ^= k;

        data += 4;
        len -= 4;
    }

    switch (len) {
    case 3:
        h ^= data[2] << 16;
    case 2:
        h ^= data[1] << 8;
    case 1:
        h ^= data[0];
        h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return h;
}

template <typename KeyType, typename ValueType>
int HashTable<KeyType, ValueType>::hashFunction(const KeyType& key) {
    unsigned int hash = MurmurHash2(&key, sizeof(key), 0);
    return hash % size;
}

template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::HashTable(int size) : size(size) {
    table = new Node<KeyType, ValueType>[size];
}

template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::~HashTable() {
    delete[] table;
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
    int index = hashFunction(key);

    while (table[index].used) {
        index = 1 + hashFunction(key);
    }

    table[index].key = key;
    table[index].value = value;
    table[index].used = true;
}

template <typename KeyType, typename ValueType>
void HashTable<KeyType, ValueType>::remove(const KeyType& key) {
    int index = hashFunction(key);

    while (table[index].used && table[index].key != key) {
        index = 1 + hashFunction(key);
    }

    if (table[index].used) {
        table[index].used = false;
    }

}

template <typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::isEmpty() const {
    for (int i = 0; i < size; ++i) {
        if (table[i].used) {
            return false;
        }
    }
    return true;
}

template <typename KeyType, typename ValueType>
int HashTable<KeyType, ValueType>::get_size() {
    return size;
}


template <typename KeyType, typename ValueType>
HashTable<KeyType, ValueType>::Iterator::Iterator(const HashTable<KeyType, ValueType>& hashTable, int index)
    : hashTable(hashTable), currentIndex(index) {}

template <typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::Iterator::operator==(const Iterator& other) const {
    return currentIndex == other.currentIndex;
}

template <typename KeyType, typename ValueType>
bool HashTable<KeyType, ValueType>::Iterator::operator!=(const Iterator& other) const {
    return !(*this == other);
}

template <typename KeyType, typename ValueType>
typename HashTable<KeyType, ValueType>::Iterator& HashTable<KeyType, ValueType>::Iterator::operator++() {
    do {
        ++currentIndex;
    } while (currentIndex < hashTable.size && !hashTable.table[currentIndex].used);
    return *this;
}

template <typename KeyType, typename ValueType>
const Node<KeyType, ValueType>& HashTable<KeyType, ValueType>::Iterator::operator*() const {
    return hashTable.table[currentIndex];
}

template <typename KeyType, typename ValueType>
typename HashTable<KeyType, ValueType>::Iterator HashTable<KeyType, ValueType>::begin() const {
    int index = 0;
    while (index < size && !table[index].used) {
        ++index;
    }
    return Iterator(*this, index);
}

template <typename KeyType, typename ValueType>
typename HashTable<KeyType, ValueType>::Iterator HashTable<KeyType, ValueType>::end() const {
    return Iterator(*this, size);
}


template class HashTable<int, int>;  
template class HashTable<int, double>;
template class HashTable<int, string>;
template class HashTable<double, int>;  
template class HashTable<double, double>;
template class HashTable<double, string>;
template class HashTable<string, int>;  
template class HashTable<string, double>;
template class HashTable<string, string>;
