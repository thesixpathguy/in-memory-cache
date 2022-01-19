/*
LRU eviction policy implementation
*/
#ifndef lru

#define lru

// libraries
#include <bits/stdc++.h>
#include "..\DataStructures\double_linked_list.h"
using namespace std;

// LRU class
template <class Key>
class LRU : public EvictionPolicy<Key>
{
private:
    DoubleLinkedList<Key> *keys; // doubly linked list for storing the keys
    map<Key, Node<Key> *> hash;  // hash map to perform deletion in O(1) in doubly linked list
public:
    // constructor
    LRU()
    {
        this->keys = new DoubleLinkedList<Key>(); // new doubly linked list
        hash.clear();
    }

    // updates the eviction policy incase of key access
    void keyAccess(Key key)
    {
        if (hash.find(key) != hash.end())
        {
            keys->Delete(hash[key]);
            keys->addNodeLast(hash[key]);
        }
        else
        {
            Node<Key> *temp = keys->addElementLast(key);
            hash[key] = temp;
        }
    }

    // evict keys according to standard eviction policy
    pair<Key, bool> evict()
    {
        Node<Key> *nodeToEvict = keys->getNodeFirst();
        Key garbage;
        if (nodeToEvict == NULL)
        {
            return {garbage, false}; // no key to evict
        }
        keys->Delete(nodeToEvict);
        hash.erase(nodeToEvict->data);
        return {nodeToEvict->data, true};
    }
};

#endif