#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  THEORY

Pointers store address of variables or a memory location.

To access address of a variable to a pointer : add & (ampersand)
To declare a pointer variable or to access vale stored in the address : add asterisk (*) before its name.

*/

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