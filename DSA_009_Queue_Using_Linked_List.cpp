#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

class Queue
{
    public:
    Node* first;
    Node* last;
    int count;
    Queue()
    {
        first=NULL;
        last=NULL;
        count=0;
    }
    void Enqueue(int data)
    {
        Node* N = new (Node);
        N->data = data;
        if(first==NULL)
            first = N;
        else last->next = N;
        last=N;
        count++;
    }
    void dequeue()
    {
        if(first== NULL)
        {
            cout << "Queue Underflow!" << endl;
            return;
        }
        count--;
        if(first->next==NULL)
        {
            delete(first);
            first=NULL;
            last=NULL;
            return;
        }
        delete(first);
        first=first->next;
    }
    int peek()
    {
        if(first==NULL) return -1;
        return (first->data);
    }
    int peekend()
    {
        if(first==NULL) return -1;
        return (last->data);
    }
    bool isEmpty()
    {
        return (first==NULL);
    }
    int size()
    {
        return count;
    }
};

int main()
{
    Queue Q;
    cout << Q.isEmpty() << endl;
    cout << Q.size() << endl;
    Q.Enqueue(10);
    cout << Q.size() << endl;
    Q.Enqueue(20);
    cout << Q.peek() << endl;
    cout << Q.isEmpty() << endl;
    cout << Q.peekend() << endl;
    cout << Q.size() << endl;

    DEQueue Q;
    cout << Q.isEmpty() << endl;
    Q.Enqueue(10);
    cout << Q.peek() << endl;
    cout << Q.isEmpty() << endl;
    cout << Q.peekend() << endl;
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Enqueue(60);
    cout << Q.peek() << endl;
    Q.dequeue();
    cout << Q.peek() << endl;
    cout << Q.peekend() << endl;
    return 69;
}