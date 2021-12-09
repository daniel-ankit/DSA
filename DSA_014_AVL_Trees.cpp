#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
    Adelson-Velsky and Landis (AVL Tree) 

    Balance Factor = |Height of L subtree - Height of R subtree| >= |1|
    The insertion function we wrote for BST would word here, and we won't have to perform rotation.

    But, if we're inserting nodes manually, we have to perform rotations to keep the AVL nature of the tree.
        - LL Insertion followed by Right rotation about first imbalanced node
        - RR Insertion followed by Left rotation about first imbalanced node
        - RL Insertion followed by Left-Right rotation about first imbalanced node
        - LR Insertion followed by Right-Left rotation about first imbalanced node

*/

struct Node
{
    int data;
    int height;
    Node* right = NULL;
    Node* left = NULL;
};

Node *create(int data)
{
    Node *N = new(Node);
    N->data = data;
    N->height = 1;
    return N;
}

int getheight(Node *root)
{
    if(root==NULL) return 0;
    return root->height;
}

int Balancefactor(Node* root)
{
    if(root==NULL) return 0;
    return (getheight(root->left) - getheight(root->right));
}

Node *rotateright(Node* Y)
{
    Node* X = Y->left;
    Node* T2 = X->right;
    Y = X;
    X->right = Y;
    Y->left = T2;
    Y->height = max(getheight(Y->right), getheight(Y->left))+1;
    X->height = max(getheight(X->right), getheight(X->left))+1;
    return X;
}

Node *rotateleft(Node* X)
{
    Node* Y = X->left;
    Node* T2 = Y->right;
    Y->left = X;
    X->right = T2;
    Y->height = max(getheight(Y->right), getheight(Y->left))+1;
    X->height = max(getheight(X->right), getheight(X->left))+1;
    return Y;
}

void inorder(Node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right); 
}

bool isBST(Node *root)
{
    static Node* prev = NULL;
    if(root!=NULL)
    {
        if(!isBST(root->left)) return 0;
        if(prev!=NULL && prev->data >= root->data) return 0;
        prev = root;
        return(isBST(root->right));
    }
    return 1;
}

void preorder(Node* root)
{
    if(root==NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

Node* insert(Node *root, int key)
{
    if(!root)
    {
        root = create(key);
        return root;
    }
    if(key > root->data)
        root->right = insert(root->right, key);
    else
        root->left = insert(root->left, key);
    return root;

    root->height = max(getheight(root->right), getheight(root->left))+1;
    int bf = Balancefactor(root);
    if(bf>1 && root->left->data > key)
        return rotateright(root);
    if(bf<-1 && root->right->data < key)
        return rotateleft(root);
    if(bf>1 && root->left->data < key)
    {
        root->left = rotateleft(root->left);
        return rotateright(root);
    }
    if(bf<-1 && root->right->data > key)
    {
        root->right = rotateright(root->right);
        return rotateleft(root);
    }
    return root;
}

int main()
{
    Node* ROOT = NULL;
    ROOT = create(45);
    ROOT->left = create(25);
    ROOT->right = create(65);

    (ROOT->left)->left = create(15);
    (ROOT->left)->right = create(35);
    (ROOT->right)->left = create(55);
    (ROOT->right)->right = create(75);

    insert(ROOT, 10);
    insert(ROOT, 0);

    insert(ROOT, 60);
    
    inorder(ROOT);
    cout << "\n";
    preorder(ROOT);
    // cout << endl << isBST(ROOT);


    return 69;
}