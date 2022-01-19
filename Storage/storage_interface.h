/*
Storage interface: Can take any kind of storage which complies with the contract of the Storage abstract class.
*/
#ifndef storage_interface

#define storage_interface

// libraries
#include <bits/stdc++.h>
using namespace std;

// Storage interface (abstract class)
template <class Key, class Value>
class Storage
{
public:
    Storage() {}
    virtual ~Storage() {}
    virtual void add(Key key, Value value) = 0; // add a key-value pair to storage
    virtual void Delete(Key key) = 0;           // delete a key from storage
    virtual pair<Value, bool> get(Key key) = 0; // gets a value for the given key (also returns whether key is present or not).
    virtual bool isFull() = 0;                  // return whether storage is full or not.
    virtual void print() = 0;                   // print the storage
};

#endif