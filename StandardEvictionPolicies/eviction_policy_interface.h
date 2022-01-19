/*
Eviction Policy interface: Can take any kind of policy which complies with the contract of the EvictionPolicy abstract class.
*/
#ifndef eviction_policy_interface

#define eviction_policy_interface

// libraries
#include <bits/stdc++.h>
using namespace std;

// EvictionPolicy interface (abstract class)
template <class Key>
class EvictionPolicy
{
public:
    EvictionPolicy() {}
    virtual ~EvictionPolicy() {}
    virtual void keyAccess(Key key) = 0; // updates the eviction policy incase of key access
    virtual pair<Key, bool> evict() = 0; // evict keys according to standard eviction policy
};

#endif