#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* prev = NULL;
    int data;
    Node* next = NULL;
};

void traverse(Node* head)
{
    if(head==NULL) return;
    Node*ptr = head;
    while(ptr->next!=head)
    {
        cout << ptr->data << " ";
        ptr=ptr->next;
    }
    cout << ptr->data << endl;
}

void reversetraverse(Node* head)
{
    if(head==NULL) return;
    Node *ptr = head->prev;
    while(ptr->prev!=head)
    {
        cout << ptr->data << " " ;
        ptr = ptr->prev;
    }
    cout << head->data << endl;
}

Node *insertatbeginning(Node *head, int dat)
{
    Node *N = new Node();
    N->data = dat;
    if(head == NULL)
    {
        N->next=N;
        N->prev=N;
        N->data = dat;
    }
    else
    {
        N->prev = head->prev;
        (head->prev)->next = N;
        N->next = head;
        head->prev=N;
    }
    return N;
}

Node *insertatend(Node* head, int dat)
{
    if(head == NULL)
    {
        head = insertatbeginning(head, dat);
        return head;
    }
    else
    {
        Node *N = new Node();
        N->data = dat;
        N->prev = head->prev;
        (head->prev)->next = N;
        N->next = head;
        head->prev=N;
    }
    return head;
}

Node *create(Node *head, int n)
{
    for(int i=1; i<=n; i++)
    {
        int dat;
        cout << "Enter data for Node " << i << " : ";
        cin >> dat; 
        head = insertatend(head, dat);
    }
    return head;
}

Node *deletefrombeginning(Node *head)
{
    Node *ptr = head;
    head = ptr->next;
    (ptr->next)->prev=ptr->prev;
    (ptr->prev)->next=ptr->next;
    free(ptr);
    return head;
}

Node *deletefromend(Node *head)
{
    Node *ptr=head->prev;
    (ptr->next)->prev = ptr->prev;
    (ptr->prev)->next=ptr->next;
    free(ptr);
    return head;
}

Node *deleteatindex(Node *head, int index)
{
    if(index == 1)
    {
        head = deletefrombeginning(head);
        return head;
    }
    Node *ptr=head;
    for(int i=1; i<index; i++)
        ptr=ptr->next;
    (ptr->prev)->next=ptr->next;
    (ptr->next)->prev = ptr->prev;
    free(ptr);
    return head;
}

Node *delet(Node *head, int data)
{
    if(head->data == data)
    {
        head = deletefrombeginning(head);
        return head;
    }
    Node *ptr=head;
    while(ptr->data!=data)
        ptr=ptr->next;
    (ptr->prev)->next=ptr->next;
    (ptr->next)->prev = ptr->prev;
    free(ptr);
    return head;
}

int main()
{
    Node * HEAD = NULL;

    HEAD = insertatbeginning(HEAD, 10);
    HEAD = insertatend(HEAD, 20);
    HEAD = insertatend(HEAD, 40);
    HEAD = insertatbeginning(HEAD, 0);
    HEAD = create(HEAD, 3);
    HEAD = deletefrombeginning(HEAD);
    HEAD = deletefromend(HEAD);
    traverse(HEAD);
    HEAD = delet(HEAD, 0);
    traverse(HEAD);
    return 69;
}