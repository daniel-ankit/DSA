//  INCOMPLETE

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DEQueue
{
    int first;
    int last;
    char* array;
    int SIZE;
    DEQueue(int N)
    {
        first=0;
        last=0;
        SIZE = N;
        array = new int;
    }
    ~DEQueue
    {
        delete[] (array);
    }
    bool empty()
    bool full()
    void push_front(char C)
    void push_back(char C)
    void pop_front()
    void pop_back()
    int size()
    char peek_front()
    char peek_back()
    void clear()
    void print()

}

int main()
{
    
    return 69;
}