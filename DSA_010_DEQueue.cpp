#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node* next;
    Node() { next = NULL; }
};

class DEQueue
{
    public:
    Node *first;
    Node* last;
    int count=0;
    DEQueue()
    {
        first = NULL;
        last = NULL;
    }
    bool empty()
    {
        return (first==NULL && last == NULL);
    }
    void push_front(char C)
    {
        Node* N = new Node();
        N->data = C;
        if(first==NULL && last == NULL) last = N;
        else N->next = first;
        first = N;
        count++;
    }
    void push_back(char C)
    {
        Node* N = new Node();
        N->data = C;
        if(first == NULL && last == NULL) first = N;
        else last->next = N;
        last = N;
        count++;
    }
    void pop_front()
    {
        if(this->empty()) return;
        if(first==last && first != NULL)
        {
            first = NULL;
            last = NULL;
            count--;
            return;
        }
        Node *ptr = first;
        first = first->next;
        delete(ptr);
        count--;
    }
    void pop_back()
    {
        if(this->empty()) return;
        if(first==last && first != NULL)
        {
            first = NULL;
            last = NULL;
            count--;
            return;
        }
        Node* ptr = first;
        while(ptr->next!=last)
            ptr = ptr->next;
        ptr->next = NULL;
        delete(last);
        last = ptr;
        count--;
    }
    int size()
    {
        return count;
    }
    char peek_front()
    {
        return first->data;
    }
    char peek_back()
    {
        return last->data;
    }
    void clear()
    {
        while(first!=NULL)
        {
            delete(first);
            first=first->next;
        }
        count = 0;
    }
    void print()
    {
        Node* ptr = first;
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        while(ptr->next != first);
        return;
    }
};

int main()
{
    DEQueue Q;
    cout << "Empty : " << Q.empty() << endl;
    Q.push_front('B');
    Q.push_front('A');
    Q.push_back('C');
    Q.push_back('D');
    Q.push_back('E');
    cout << "Empty : " << Q.empty() << endl;
    cout << "Front Element: " << Q.peek_front() << endl;
    cout << "Back Element: " << Q.peek_back() << endl;
    Q.pop_back();
    Q.pop_front();
    cout << "Front Element: " << Q.peek_front() << endl;
    cout << "Back Element: " << Q.peek_back() << endl;
    Q.push_front('A');
    Q.push_back('E');
    Q.print();
    
    return 69;
}