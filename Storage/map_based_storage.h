/*
Hash map based storage which complies with storage interface.
O(log n) time per query.
*/
#ifndef map_based_storage

#define map_based_storage

// libraries
#include <bits/stdc++.h>
using namespace std;

// Map Based storage class
template <class Key, class Value>
class MapBasedStorage : public Storage<Key, Value>
{
private:
    int capacity;            // capacity of the storage
    map<Key, Value> storage; // data structure for storage

public:
    // constructor
    MapBasedStorage(int capacity)
    {
        this->capacity = capacity;
        storage.clear();
    }

    // add a key-value pair to storage
    void add(Key key, Value value)
    {
        storage[key] = value;
    }

    // deletes a key from storage
    void Delete(Key key)
    {
        if (storage.find(key) == storage.end())
        {
            cout << "Storage deletion aborted. Key not present.\n";
            return;
        }
        storage.erase(key);
    }

    // gets a value for the given key.
    // bool represents whether key is present or not in the storage.
    pair<Value, bool> get(Key key)
    {
        Value value;
        if (storage.find(key) == storage.end())
        {
            return {value, false}; // garbage value
        }
        else
        {
            value = storage[key];
            return {value, true};
        }
    }

    // returns whether storage is full or not
    bool isFull()
    {
        if (storage.size() >= capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // prints the storage
    void print()
    {
        for (auto x : storage)
        {
            cout << x.first << " ";
        }
        cout << endl;
    }
};

#endif