/*
LIFO eviction policy implementation
*/
#ifndef lifo

#define lifo

// libraries
#include <bits/stdc++.h>
using namespace std;

//LIFO class
template <class Key>
class LIFO : public EvictionPolicy<Key>
{
private:
    stack<Key> keys; // stack needed for LIFO
    set<Key> hash;   // hash to keep a track of keys in the stack

public:
    // constructor
    LIFO()
    {
        stackClear(keys);
        hash.clear();
    }

    // updates the eviction policy incase of key access
    void keyAccess(Key key)
    {
        if (hash.count(key) == 0)
        {
            keys.push(key);
            hash.insert(key);
        }
    }

    // evict keys according to standard eviction policy
    pair<Key, bool> evict()
    {
        Key garbage;
        if (keys.empty())
        {
            return {garbage, false}; // no key to evict
        }
        Key keyToEvict = keys.top();
        keys.pop();
        hash.erase(keyToEvict);
        return {keyToEvict, true};
    }

    // clears the stack
    void stackClear(stack<Key> &key)
    {
        while (!key.empty())
        {
            key.pop();
        }
    }
};

#endif