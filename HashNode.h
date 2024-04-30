/*
-----------------------------------------------HashNode.h------------------------------------
    Fang Wu, Shivam Bakshi, Selina Nguyen CSS 343 B
    May 27, 2023
    June 2, 2023
    ------------------------------------------------------------------------------------------
    Purpose - 
    -------------------------------------------------------------------------------------------
    
 ----------------------------------------------------------------------------------------------
 */
#ifndef HASHNODE_H
#define HASHNODE_H

template <typename KeyT, typename ValT>
class HashNode {
private:
    KeyT key;
    ValT value;
    HashNode* next;

public:
    HashNode(const KeyT& k, const ValT& v) : key(k), value(v), next(nullptr) {}

    KeyT getKey() const {
        return key;
    }

    ValT getValue() const {
        return value;
    }

    void setValue(const ValT& v) {
        value = v;
    }

    HashNode* getNext() const {
        return next;
    }

    void setNext(HashNode* n) {
        next = n;
    }
};

#endif // HASHNODE_H
