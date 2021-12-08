#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

class Stack
{
public:
    int top;
    int array[MAX];

    Stack() { top = -1; }
    void push(int x)
    {
        if(top >= MAX-1)
        {
            cout << "Stack Full" << endl;
            return;
        }
        array[++top]=x;
        cout << x << " Pushed." << endl;
    }

    void pop()
    {
        if(top==-1)
        {
            cout << "Stack Empty" << endl;
            return;
        }
        cout << array[top];
        top--;
    }

    bool Isfull()
    {
        return (top==MAX-1);
    }

    bool Isempty()
    {
        return (top==-1);
    }

    int peek()
    {
        if(top<0)
        {
            cout << "Stack Empty!" << endl;
            return 0;
        }
        return array[top];
    }

    void print()
    {
        if(Isempty())
        {
            cout << "Stack Empty!" << endl;
            return;
        }
        for(int i=top; i>=0; i--)
            cout << array[i] << endl;
    }

};

int main()
{
    Stack S;
    cout << S.Isempty() << endl;
    S.push(10);
    S.push(20);
    S.push(30);
    S.push(40);
    S.push(50);
    S.push(60);
    S.push(70);
    cout << S.peek() << endl;
    cout << S.Isempty();
    return 69;
}