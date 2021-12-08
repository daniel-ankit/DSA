#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
#define MAX 10001

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
    }
};

/*  IMPLEMENTATION

class Stack
{
public:
    int top;
    char array[MAX];

    Stack() { top = -1; }
    void push(char x)
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

*/

int main()
{
    // stack<char> S;
    // string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // for (int i = 0; i < str.length(); i++)
    //     S.push(str[i]);
    // for (int i = 0; i < str.length(); i++)
    // {
    //     cout << S.top();
    //     S.pop();
    // }
    Node* HEAD = NULL;
    Node* N1 = new Node(10);
    Node* N2 = new Node(20);
    Node* N3 = new Node(30);
    Node* N4 = new Node(40);
    Node* N5 = new Node(50);

    HEAD = N1;
    N1->next = N2;
    N2->next = N3;
    N3->next = N4;
    N4->next = N5;
    N5->next = NULL;

    stack <Node*> S;
    Node* ptr = HEAD;
    while(ptr!=NULL)
    {
        S.push(ptr);
        ptr = ptr->next;
    }
    ptr = S.top();
    HEAD = ptr;
    S.pop();
    while(!S.empty())
    {
        ptr->next = S.top();
        S.pop();
        ptr = ptr->next;
    }
    ptr->next = NULL;
    ptr=HEAD;
    
    while(ptr!=NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    return 69;
}