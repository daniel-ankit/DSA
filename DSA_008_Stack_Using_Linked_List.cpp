#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* link;
};

Node* push(Node* top, int data)
{
    Node *New = new Node();
    New->data = data;
    New->link = top;
    top = New;
    cout << data << " Pushed!" << endl;
    return top;
}

Node* pop(Node *top)
{
    if(top==NULL)
    {
        cout << "Stack Empty!" << endl;
        return top;
    }
    Node *ptr = top;
    top = top->link;
    cout << ptr->data << " Popped!" << endl;
    free(ptr);
    return top;
}

bool Isempty(Node *top)
{
    return (top==NULL);
}

void print(Node *top)
{
    if(top==NULL)
    {
        cout << "Empty Stack!" << endl;
        return;
    }
    while(top!=NULL)
    {
        cout << top->data << endl;
        top = top->link;
    }
}

void peek(Node *top)
{
    if(top==NULL)
    {
        cout << "Stack Empty!" << endl;
        return;
    }
    cout << top->data << endl;
}

int main()
{
    Node *top = NULL;
    cout << Isempty(top) << endl;
    top = push(top, 10);
    cout << Isempty(top) << endl;
    top = push(top, 20);
    top = pop(top);
    top = push(top, 40);
    top = push(top, 50);
    print(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    peek(top); 
    return 69;
}