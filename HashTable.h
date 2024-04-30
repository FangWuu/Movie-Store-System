/*
-----------------------------------------------HashTable.h------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - 
    -------------------------------------------------------------------------------------------
    
 ----------------------------------------------------------------------------------------------
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashNode.h"
#include <functional>
#include <vector>

template<typename KeyT, typename ValT>
class HashTable {
private:
    static const int SIZE = 100;
    HashNode<KeyT, ValT>* hashTable[SIZE];
    std::hash<KeyT> key_hash;  // hash function for KeyT

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            hashTable[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            HashNode<KeyT, ValT>* prevNode = hashTable[i];
            while (prevNode) {
                HashNode<KeyT, ValT>* temp = prevNode;
                prevNode = prevNode->getNext();
                delete temp;
            }
            hashTable[i] = nullptr;
        }
    }

    std::vector<ValT> getAllValues() {
        std::vector<ValT> values;
        for (int i = 0; i < SIZE; i++) {
            HashNode<KeyT, ValT>* currNode = hashTable[i];
            while (currNode) {
                values.push_back(currNode->getValue());
                currNode = currNode->getNext();
            }
        }
        return values;
    }

    void insert(const KeyT& key, const ValT& value) {
        unsigned long hashValue = key_hash(key) % SIZE;
        HashNode<KeyT, ValT>* prevNode = nullptr;
        HashNode<KeyT, ValT>* currNode = hashTable[hashValue];
        while (currNode && currNode->getKey() != key) {
            prevNode = currNode;
            currNode = currNode->getNext();
        }
        if (!currNode) {
            HashNode<KeyT, ValT>* newNode = new HashNode<KeyT, ValT>(key, value);
            if (!prevNode) {
                hashTable[hashValue] = newNode;
            } else {
                prevNode->setNext(newNode);
            }
        } else {
            currNode->setValue(value);
        }
    }

    bool retrieve(const KeyT& key, ValT& value) {
        unsigned long hashValue = key_hash(key) % SIZE;
        HashNode<KeyT, ValT>* prevNode = hashTable[hashValue];
        while (prevNode) {
            if (prevNode->getKey() == key) {
                value = prevNode->getValue();
                return true;
            }
            prevNode = prevNode->getNext();
        }
        return false;
    }

    void remove(const KeyT& key) {
        unsigned long hashValue = key_hash(key) % SIZE;
        HashNode<KeyT, ValT>* prevNode = nullptr;
        HashNode<KeyT, ValT>* currNode = hashTable[hashValue];
        while (currNode && currNode->getKey() != key) {
            prevNode = currNode;
            currNode = currNode->getNext();
        }
        if (!currNode) {
            return;  // Key not found, do nothing
        }
        if (!prevNode) {
            hashTable[hashValue] = currNode->getNext();
        } else {
            prevNode->setNext(currNode->getNext());
        }
        delete currNode;
    }
};

#endif // HASHTABLE_H



