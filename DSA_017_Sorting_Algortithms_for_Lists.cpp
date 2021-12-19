#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

Node *create(Node *head, int val)
{
    Node* N= new(Node);
    N->data = val;
    if(head==NULL) return N;
    Node* p = head;
    while(p->right!=NULL) p = p->right;
    p->right = N;
    (p->right)->left = p;
    return head;
}

void traversal(Node* head)
{
    while(head!=NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
}

void selectionsort(Node *head)
{
    // Selection Sort Implementation
    if(head==NULL || head->right==NULL) return;
    Node* p = head, *q = NULL;
    while(p!=NULL)
    {
        q = p->right;
        while(q!=NULL)
        {
            if(p->data > q->data)
                swap(p->data, q->data);
            q = q->right;
        }
        p = p->right;
    }
}

void reversetraversal(Node* head)
{
    stack <int> S;
    while(head!=NULL)
    {
        S.push(head->data);
        head = head->right;
    }
    while(!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
}

void mergesort(Node *head)
{
    
}

int main()
{
    Node *head = NULL;
    head = create(head, 10);
    head = create(head, 15);
    head = create(head, 0);
    head = create(head, 20);
    head = create(head, 30);
    head = create(head, 25);
    head = create(head, -5);
    selectionsort(head);
    // traversal(head);
    reversetraversal(head);
    return 69;
}