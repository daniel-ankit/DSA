#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *create(Node *head, int dat)
{
    Node *N = new Node();
    N->data = dat;
    if (head == NULL)
    {
        head = N;
        N->next = head;
        return head;
    }
    Node *ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->next = N;
    N->next = head;
    return head;
}

void traverse(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
    cout << endl;
}

Node *insertatbeginning(Node *head, int dat)
{
    Node *N = new Node(), *ptr = head;
    if (head == NULL)
    {
        head = create(head, dat);
        return head;
    }
    N->data = dat;
    N->next = head;
    while (ptr->next != head)
        ptr = ptr->next;
    head = N;
    ptr->next = N;
    return head;
}

Node *insertatend(Node *head, int dat)
{
    if (head == NULL)
    {
        head = insertatbeginning(head, dat);
        return head;
    }
    head = create(head, dat);
    return head;
}

Node *createnodes(Node *head, int n)
{
    for (int i = 1; i <= n; i++)
    {
        int dat;
        cout << "Enter data for Node " << i << ": ";
        cin >> dat;
        head = create(head, dat);
    }
    return head;
}

Node *insertat(Node *head, int index, int dat)
{
    if (index == 1)
    {
        head = insertatbeginning(head, dat);
        return head;
    }
    Node *ptr = head;
    int count=0;
    index -= 2;
    while(ptr->next!=head)
    {
        count++;
        ptr=ptr->next;
    }
    ptr=head;
    if(index<=count)
    {
        while (index--)
            ptr = ptr->next;
        Node *N = new Node();
        N->data = dat;
        N->next = ptr->next;
        ptr->next = N;
    }
    return head;
}

Node *deletefirstnode(Node *head)
{
    if (head->next == head || head == NULL)
    {
        free(head);
        head = NULL;
    }
    Node *ptr = head;
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->next = head->next;
    head = head->next;
    return head;
}

Node *deletelastnode(Node *head)
{
    if (head->next == head || head == NULL)
    {
        free(head);
        head = NULL;
    }
    Node *ptr = head;
    while ((ptr->next)->next != head)
        ptr = ptr->next;
    ptr->next = head;
    return head;
}

Node *deleteatindex(Node *head, int index)
{
    if(index==1) //Deleting first index
    {
        head = deletefirstnode(head);
        return head;
    }
    Node *ptr = head;
    int count=0;
    index--;
    while(ptr->next!=head)  //counting number of nodes
    {
        count++;
        ptr=ptr->next;
    }
    ptr=head->next;   // Pointer to the node to be deleted - to free the memory
    Node *q = head;  // Pointer to the node before the node to be deleted
    if(index<count)
    {
        index--;
        while (index--)
        {
            ptr = ptr->next;
            q = q->next;
        }
        q->next = ptr->next;
        free(ptr);
        return head;
    }
    if(index==count) //Deleting last index
    {
        head = deletelastnode(head);
        return head;
    }
    return head;
}

Node* delet(Node* head, int dat)
{
    Node *ptr = head;
    int count=0;
    while(ptr->next!=head)  //counting number of nodes
    {
        count++;
        ptr=ptr->next;
    }
    ptr=head;
    for(int i=1; i<count; i++)
    {
        if(ptr->data==dat)
        {
            head = deleteatindex(head, i);
            return head;
        }
        ptr = ptr->next;
    }
    return head;
}

Node* reverse(Node *head)
{
    Node* prev = NULL;
    Node* current = head;
    Node* next;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    head->next = prev;
    head = prev;
    return head;
}

int main()
{
    Node *HEAD = NULL;
    HEAD = create(HEAD, 10);
    HEAD = create(HEAD, 20);

    HEAD = insertatbeginning(HEAD, 0);
    HEAD = deletefirstnode(HEAD);

    HEAD = insertatend(HEAD, 30);
    HEAD = deletelastnode(HEAD);

    HEAD = insertat(HEAD, 6, 70);
    HEAD = deleteatindex(HEAD, 4);

    HEAD = createnodes(HEAD, 2);
    traverse(HEAD);

    HEAD = reverse(HEAD);
    traverse(HEAD);

    HEAD = delet(HEAD, 20);
    traverse(HEAD);
    return 69;
}