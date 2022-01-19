#include <bits/stdc++.h>
#include "cache.h"
using namespace std;

int main()
{
    Cache<int,int> *test= new Cache<int,int>(new LIFO<int>(),new MapBasedStorage<int,int>(5));
    test->put(2,4);
    test->put(4,8);
    test->put(6,12);
    test->put(2,5);
    int res=test->get(2);
    cout<<res<<endl;
    test->put(8,16);
    res=test->get(12);
    cout<<res<<endl;
    test->put(10,20);
    res=test->get(4);
    cout<<res<<endl;
    test->put(14,28);
    cout<<"rojg";
    res=test->get(6);
    cout<<res<<endl;
    return 0;
}