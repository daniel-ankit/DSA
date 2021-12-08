#include<iostream>
#include<bits/stdc++.h>
using namespace std;
   
struct Node
{
    char data;
    Node* left = NULL;
    Node* right = NULL;
};

void InorderTraversal(Node* root)
{
    // Down
    if(root)
    {
        InorderTraversal(root->left);
        cout << root->data << " ";
        InorderTraversal(root->right);
    }
}

void PreorderTraversal(Node* root)
{
    // Left
    if(root)
    {
        cout << root->data << " ";
        InorderTraversal(root->left);
        InorderTraversal(root->right);
    }
    cout << endl;
}

void PostorderTraversal(Node* root)
{
    // Right
    if(root)
    {
        InorderTraversal(root->left);
        InorderTraversal(root->right);
        cout << root->data << " ";
    }
    cout << endl;
}

class Binary_Tree
{
    public:
    Node* Root(char ch)
    {
        Node* N = new(Node);
        N->data = ch;
        return N;
    }
    Node* Left(char ch, Node *parent)
    {
        return parent;
    }
};

Node* Create_Node(char ch)
{
    Node* N = new(Node);
    N->data = ch;
    return N;
}

int main()
{
    Node *ROOT;
    ROOT = Create_Node('A');

    ROOT->left = Create_Node('B');
    ROOT->right = Create_Node('C');

    (ROOT->left)->left = Create_Node('D');
    (ROOT->left)->right = Create_Node('E');

    (ROOT->right)->left = Create_Node('F');
    (ROOT->right)->right = Create_Node('G');

    PreorderTraversal(ROOT);
    InorderTraversal(ROOT);
    PostorderTraversal(ROOT);
    
    return 69;
}