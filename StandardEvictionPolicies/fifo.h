/*
FIFO eviction policy implementation
*/
#ifndef fifo

#define fifo

// libraries
#include <bits/stdc++.h>
using namespace std;

//FIFO class
template <class Key>
class FIFO : public EvictionPolicy<Key>
{
private:
    queue<Key> keys; // queue needed for FIFO
    set<Key> hash;   // hash to keep a track of keys in the queue

public:
    // constructor
    FIFO()
    {
        queueClear(keys);
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
        Key keyToEvict = keys.front();
        keys.pop();
        hash.erase(keyToEvict);
        return {keyToEvict, true};
    }

    // clears the queue
    void queueClear(queue<Key> &key)
    {
        while (!key.empty())
        {
            key.pop();
        }
    }
};

#endif