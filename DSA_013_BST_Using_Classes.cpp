#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BST
{
    public : 
    int data;
    BST *left, *right;
    BST()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    BST(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
    bool isBST(BST *root)
    {
        //  This function  is actually of no use, as this class always inserts values as
        //  it should be in a BST, so it will always return value true.
        static BST* prev = NULL;
        if(root!=NULL)
        {
            if(!isBST(root->left)) return 0;
            if(prev!=NULL && root->data <= prev->data) return 0;
            prev = root;
            return(isBST(root->right));
        }
        return 1;
    }
    BST* search(BST* root, int key)
    {
        while(root!=NULL)
        {
            if(root->data==key)
            return root;
            if(key < root->data) root = root->left;
            else root = root->right;
        }
        return NULL;
    }
    BST* insert(BST* root, int key)
    {
        if(root==NULL)
            return new BST(key);
        if(root->data < key)
            root->right = insert(root->right, key);
        if(root->data > key)
            root->left = insert(root->left, key);
        return root;
    }
    void inorder(BST *root)
    {
        if(!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void postorder(BST* root)
    {
        if(!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    BST *FindMin(BST* root)
    {
        while(root->left!=NULL) root = root->left;
        return root;
    }
    BST* Delete(BST *root, int key)
    {
        if(root==NULL) return NULL;
        else if(root->data > key) root->left = Delete(root->left, key);
        else if(root->data < key) root->right = Delete(root->right, key);
        else
        {
            if(root->right==NULL && root->left==NULL)
            {
                delete(root);
                root = NULL;
            }
            else if(root->right==NULL)
            {
                BST *temp = root;
                root = root->left;
                delete temp;
            }
            else if(root->left==NULL)
            {
                BST *temp = root;
                root = root->right;
                delete temp;
            }
            else
            {
                BST* temp = FindMin(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        return root;
    }
};

int main()
{
    BST *ROOT=NULL, TREE;
    ROOT = TREE.insert(ROOT, 50);
    TREE.insert(ROOT, 45);
    TREE.insert(ROOT, 55);
    TREE.insert(ROOT, 40);
    TREE.insert(ROOT, 47);
    TREE.insert(ROOT, 52);
    TREE.insert(ROOT, 60);
    TREE.insert(ROOT, 20);
    TREE.insert(ROOT, 42);
    TREE.insert(ROOT, 51);
    TREE.insert(ROOT, 53);
    TREE.insert(ROOT, 65);
    TREE.insert(ROOT, 70);
    TREE.insert(ROOT, 75);
    TREE.inorder(ROOT);

    // TREE.postorder(ROOT);
    // BST* N = TREE.search(ROOT, 70);
    // cout << N->data << " Found.";

    // cout << TREE.isBST(ROOT);
    TREE.Delete(ROOT, 53);
    cout<< endl;

    TREE.inorder(ROOT);
    return 69;
}