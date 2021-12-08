#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

void traverse(Node *head)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void reverse_traverse(Node* head)
{
    while(head->next!=NULL)
    head=head->next;
    while(head!=NULL)
    {
        cout << head->data <<" ";
        head=head->prev;
    }
    cout << endl;
}

Node *create(Node* head)
{
    int dat;
    Node *N = new Node();
    cout << "Enter Node data: ";
    cin >> dat;
    N->data=dat;
    N->next=NULL;
    N->prev=NULL;
    if(head==NULL) head=N;
    else
    {
        Node *p=head;
        while(p->next!=NULL)
            p=p->next;
        p->next=N;
        N->prev=p;
    }
    return head;
}

Node* create(Node* head, int n)
{
    for(int i=0; i<n; i++)
        head = create(head);
    return head;
}

Node *insertatbeginning(Node *head)
{
    if(head==NULL)
    {
        head=create(head);
        return head;
    }
    Node *N = new Node();
    int dat;
    cout << "Enter node data: ";
    cin >> dat;
    N->next = head;
    head->prev=N;
    head=N;
    N->data=dat;
    N->prev = NULL;
    return head;
}

Node* insetatindex(Node* head, int index)
{
    Node *ptr=head, *N = new Node();

    index-=2;
    while(index--)
    ptr=ptr->next;

    int dat;
    cout << "Enter node data: ";
    cin >> dat;
    N->data=dat;

    N->next = ptr->next;
    (ptr->next)->prev = N;
    ptr->next=N;
    N->prev = ptr;
    return head;
}

Node *deletefrombeginning(Node* head)
{
    if(head==NULL) return head;
    Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

Node *deletefromend(Node* head)
{
    if(head==NULL) return head;
    Node *ptr = head;
    while(ptr->next!=NULL) ptr=ptr->next;
    (ptr->prev)->next=NULL;
    free(ptr);
    return head;
}

Node* deleteatindex(Node* head, int index)
{
    if(index==1)
    {
        head = deletefrombeginning(head);
        return head;
    }
    Node* ptr=head;
    for(int i=1; i<index; i++)
        ptr = ptr->next;
    if(ptr->next==NULL)
    {
        head = deletefromend(head);
        return head;
    }
    (ptr->prev)->next = ptr->next;
    (ptr->next)->prev = ptr->prev;
    free(ptr);
    return head;
}

Node* del(Node* head, int data)
{
    if(head->data==data)
    {
        head = deletefrombeginning(head);
        return head;
    }
    Node* ptr=head;
    while(ptr->data!=data)
        ptr = ptr->next;
    if(ptr->next==NULL)
    {
        head = deletefromend(head);
        free(ptr);
        return head;
    }
    (ptr->next)->prev=ptr->prev;
    (ptr->prev)->next = ptr->next;
    free(ptr);
    return head;
}

int main()
{
    Node *HEAD=NULL;
    HEAD = create(HEAD, 5);
    HEAD = insertatbeginning(HEAD);
    traverse(HEAD);
    HEAD = deletefrombeginning(HEAD);
    traverse(HEAD);
    HEAD = deletefromend(HEAD);
    traverse(HEAD);
    HEAD = deleteatindex(HEAD, 4);
    traverse(HEAD);
    HEAD = del(HEAD, 10);
    traverse(HEAD);
    return 69;
}