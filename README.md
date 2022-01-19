
# In Memory Cache

Implemented In-Memory Cache library in C++. 
1. Supports Get and Put methods in the cache.
2. Used standard eviction policies like FIFO, LIFO, LRU.
3. For storage, hash map has been used.

## How to use?
Step 1: Include "cache.h" header file.

Step 2: Create an object of class Cache with Key and Value datatypes.

    for LRU: 
    Cache<Key,Value> *test= new Cache<Key,Value>(new LRU<Key>(),new MapBasedStorage<Key,Value>(Capacity));

    for FIFO: 
    Cache<Key,Value> *test= new Cache<Key,Value>(new FIFO<Key>(),new MapBasedStorage<Key,Value>(Capacity));

    for LIFO: 
    Cache<Key,Value> *test= new Cache<Key,Value>(new LIFO<Key>(),new MapBasedStorage<Key,Value>(Capacity));

Step 3: Use get and put methods.

    Value= test.get(Key)
    test.put(Key,Value)


