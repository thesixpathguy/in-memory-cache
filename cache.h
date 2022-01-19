/*
In Memory Cache implementation with GET and PUT methods 
*/

#ifndef cache
#define cache

// libraries included
#include <bits/stdc++.h>
#include "Storage\storage_interface.h"
#include "Storage\map_based_storage.h"
#include "StandardEvictionPolicies\eviction_policy_interface.h"
#include "StandardEvictionPolicies\lru.h"
#include "StandardEvictionPolicies\fifo.h"
#include "StandardEvictionPolicies\lifo.h"
#include "DataStructures\double_linked_list.h"
using namespace std;

// generic cache class which expects a eviction policy type and a storage type
template <class Key, class Value>
class Cache
{
private:
    // expects any eviction policy which complies with eviction policy interface
    EvictionPolicy<Key> *evictionPolicy;
    // expects any storage type which complies with storage interface
    Storage<Key, Value> *storage;

public:
    Cache(EvictionPolicy<Key> *evictionPolicy, Storage<Key, Value> *storage);
    // adds a new value to the cache
    void put(Key key, Value value);
    // get the value of given key from the cache
    Value get(Key key);
};

// constructor
template <class Key, class Value>
Cache<Key, Value>::Cache(EvictionPolicy<Key> *evictionPolicy, Storage<Key, Value> *storage)
{
    this->evictionPolicy = evictionPolicy;
    this->storage = storage;
}

// put method with eviction if storage full
template <class Key, class Value>
void Cache<Key, Value>::put(Key key, Value value)
{
    if (this->storage->isFull()) //storage full: perform eviction
    {
        // this->storage->print();
        cout << "Storage is full. Eviction initiated.\n";
        pair<Key, bool> keyToDelete = this->evictionPolicy->evict(); // eviction
        if (keyToDelete.second == false)
        {
            cout << "Storage is full but no key to delete, please check the capacity. Could not store key.\n";
            return;
        }
        pair<Value, bool> check = this->storage->get(keyToDelete.first);
        if (check.second == false)
        {
            cout << "Key to evict not present in storage. Trying new key to evict.\n";
            put(key, value);
            return;
        }
        this->storage->Delete(keyToDelete.first);
        put(key, value);
    }
    else // storage not full: simply add the Key - Value pair
    {
        this->storage->add(key, value);
        this->evictionPolicy->keyAccess(key);
    }
    // this->storage->print();
}

// get method
template <class Key, class Value>
Value Cache<Key, Value>::get(Key key)
{
    pair<Value, bool> value = this->storage->get(key);
    this->evictionPolicy->keyAccess(key);
    if (value.second == false)
    {
        cout << "Key does not exist. Returning garbage.\n";
    }
    return value.first;
}

#endif