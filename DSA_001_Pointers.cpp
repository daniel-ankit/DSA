#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int* create()
{  
    int num;
    return &num;
}

int main()
{
    void* ptr=NULL;  //  NULL(0) Void Pointers
    int n=10;
    ptr = &n;
    cout << *((int*)ptr) <<  endl;  // Type casting (void*) pointer into (int*) pointer
    cout << sizeof(NULL) << endl;  // Depends upon System
    ptr = (int*)create();
    cout << ptr;
    return 69; 
}