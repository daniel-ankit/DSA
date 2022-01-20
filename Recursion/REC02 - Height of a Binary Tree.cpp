#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left = NULL;
    Node* right = NULL;
};

void inorder(Node* head)
{
    if(head==NULL) return;
    inorder(head->left);
    cout << head->data << " ";
    inorder(head->right);
}

int heightofBST(Node* head)
{
    if(head==NULL) return 0;
    int leftheight = heightofBST(head->left);
    int rightheight = heightofBST(head->right);
    return max(leftheight, rightheight)+1;
}

int main()
{
    Node* HEAD = NULL;
    HEAD = new Node();
    HEAD->data = 10;

    HEAD->left = new Node(); 
    HEAD->left->data = 20;
    HEAD->right = new Node(); 
    HEAD->right->data = 30;

    HEAD->left->left = new Node(); 
    HEAD->left->left->data = 40;
    HEAD->left->right = new Node(); 
    HEAD->left->right->data = 50;

    HEAD->right->left = new Node(); 
    HEAD->right->left->data = 60;
    HEAD->right->right = new Node(); 
    HEAD->right->right->data = 70;

    HEAD->right->right->left = new Node();
    HEAD->right->right->left->data = 80;

    inorder(HEAD);
    cout << heightofBST(HEAD);
    return 69;
}