#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  THEORY

*/

struct Node
{
    int data;
    Node* next;
};

void traverse(Node* head)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head=head->next;
    }
    cout <<  endl;
}

void traverse_reursively(Node* head)
{
    if(head==NULL) return;
    cout << head->data << " ";
    traverse_reursively(head->next);
}

Node* create_node(Node* head, int dat=0)
{
    Node* N = new Node();
    cout << "Enter Node data: ";
    cin >> dat;
    N->data=dat;
    N->next=NULL;
    if(head==NULL)  //This will save the space that will be consumed for making iterator pointer
    {
        head=N;
        return N;
    }
    else
    {
        Node *p=head;  //pointer for iteration
        while(p->next!=NULL)
        p=p->next;
        p->next = N;
        return head;
    }
}

Node* insertatfirst(Node *head, int dat=0)
{
    Node* N = new Node();
    N->next = head;
    cout << "Enter Node data: ";
    cin >> dat;
    N->data=dat;
    head = N;
    return head;
}

Node* insertatindex(Node* head, int index)
{
    int dat=0;
    if(index==1)
    {
        head = insertatfirst(head, dat);
        return head;
    }
    cout << "Enter Node data: ";
    cin >> dat;
    Node* ptr=head;
    Node* N = new Node();
    N->data=dat;
    index-=2;
    while(index--)
    ptr = ptr->next;
    N->next = ptr->next;
    ptr->next = N;
    return head;
}

Node *create(Node* head, int n)
{
    for(int i=0; i<n; i++)
    head = create_node(head, n);
    return head;
}

Node* deletefromend(Node* head)
{
    if(head==NULL)
        return head;
    Node *p=head, *q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

Node* deleteformbeginning(Node* head)
{
    if(head==NULL)
        return head;
    Node *p=head;
    head = p->next;
    free(p);
    return head;
}

Node* deleteatindex(Node* head, int index)
{
    if(index==1)
    {
        head = deleteformbeginning(head);
        return head;
    }
    Node* p=head, *q=head->next;
    index-=2;
    while(index--)
    {
        p=p->next;
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

Node* reverse(Node *head)
{
    Node* p=NULL, *q=NULL, *count=head;
    while(count!=NULL)
    {
        q=count->next;
        count->next = p;
        p=count;
        count=q;
    }
    return p;
}

void traverse_reursively_reverse(Node* head)
{  
    if(head==NULL) return;
    traverse_reursively_reverse(head->next);
    cout << head->data << " ";
}

int main()
{
    Node* HEAD = NULL;
    HEAD = create_node(HEAD);
    HEAD = create_node(HEAD);
    HEAD = insertatindex(HEAD, 3);
    HEAD = insertatfirst(HEAD);
    HEAD = create_node(HEAD);
    HEAD = create_node(HEAD);
    traverse_reursively(HEAD);
    HEAD = create(HEAD, 10);
    traverse(HEAD);
    HEAD = deletefromend(HEAD);
    traverse(HEAD);
    HEAD = deleteformbeginning(HEAD);
    traverse(HEAD);
    HEAD = deleteatindex(HEAD, 2);
    traverse(HEAD);
    HEAD = reverse(HEAD);
    traverse(HEAD);
    return 69;
}