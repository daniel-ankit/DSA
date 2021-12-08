#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define capacity  101

int A[capacity];
int top = -1;

void push(int data)
{
    if(top==capacity-1)
    {
        cout << "Stack Overflow";
        return;
    }
    A[++top] = data;
}

void pop()
{
    if(top==-1)
    {
        cout << "Stack Underflow";
        return;
    }
    top--;
}

void peek()
{
    cout << A[top];
}

bool isEmpty()
{
    if(top==-1) return 1;
    return 0;
}

bool isFull()
{
    if(top==capacity-1) return 1;
    return 0;
}

void print()
{
    for(int i=0; i<=top; ++i)
    cout << A[i] << endl;
}

int main()
{
    push(2);
    push(3);
    push(7);
    pop();
    pop();
    pop();
    push(12);
    print();
    return 69;
}