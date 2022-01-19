#include <bits/stdc++.h>
#include "cache.h"
using namespace std;

void test_LRU()
{
    Cache<int,int> *test= new Cache<int,int>(new LRU<int>(),new MapBasedStorage<int,int>(5));
    test->put(2,4);
    test->put(4,8);
    test->put(6,12);
    test->put(2,5);
    int res=test->get(2);
    cout<<res<<endl; // expected 5
    test->put(8,16);
    res=test->get(12);
    cout<<res<<endl; // key doesnt exist
    test->put(10,20);
    res=test->get(4); 
    cout<<res<<endl; // expected 8
    test->put(14,28);
    res=test->get(6);
    cout<<res<<endl; // key not found
}

void test_FIFO()
{
    Cache<int,int> *test= new Cache<int,int>(new FIFO<int>(),new MapBasedStorage<int,int>(5));
    test->put(2,4);
    test->put(4,8);
    test->put(6,12);
    test->put(2,5);
    int res=test->get(2);
    cout<<res<<endl; // expected 5
    test->put(8,16);
    res=test->get(12);
    cout<<res<<endl; // key does not exist
    test->put(10,20);
    res=test->get(4);
    cout<<res<<endl; // expected 8
    test->put(14,28); 
    res=test->get(6); // expected 12
    res=test->get(2);
    cout<<res<<endl; // key does not exist
}

void test_LIFO()
{
    Cache<int,int> *test= new Cache<int,int>(new LIFO<int>(),new MapBasedStorage<int,int>(5));
    test->put(2,4);
    test->put(4,8);
    test->put(6,12);
    test->put(2,5);
    int res=test->get(2);
    cout<<res<<endl; // expected 5
    test->put(8,16);
    res=test->get(12);
    cout<<res<<endl; // key does not exist
    test->put(10,20);
    res=test->get(4);
    cout<<res<<endl; // expected 8
    test->put(14,28); 
    res=test->get(6); // expected 12
    res=test->get(10);
    cout<<res<<endl; // key does not exist
}

int main()
{

/* uncomment the below one by one to test */

    // test_FIFO();
    // test_LIFO();
    // test_LRU();
    return 0;
}