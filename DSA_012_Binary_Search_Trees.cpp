#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* right = NULL;
    Node* left = NULL;
};

Node* create(int data)
{
    Node *N = new(Node);
    N->data = data;
    return N;
}

vector<int> vectorinordertraversal(Node* root)
{
    static vector<int> V;
    if(root==NULL) return V;
    vectorinordertraversal(root->left);
    V.push_back(root->data);
    vectorinordertraversal(root->right);
    return V;
}

void inordertraversal(Node* root)
{
    if(root==NULL) return;
    inordertraversal(root->left);
    cout << root->data << " ";
    inordertraversal(root->right);
}

bool isBST(Node *root)
{
    // BASED ON INORDER TRAVERSAL
    vector<int> V = vectorinordertraversal(root);
    for(int i=0; i<V.size()-1; i++)
    {
        if(V[i]>=V[i+1])
            return 0;
    }
    return 1;
}

bool isBST2(Node *root)
{
    // WRONG METHOD - as it compares only root-left-right and not the entire tree
    if(root==NULL) return 1;
    if(!isBST2(root->left) || !isBST2(root->right)) return 0;
    if(root->right!=NULL && (root->right)->data <= root->data) return 0;
    if(root->left!=NULL && (root->left)->data >= root->data) return 0; 
    return 1;
}

bool isBST3(Node* root)
{
    // USING IN-ORDER TRAVERSAL METHOD
    static Node* prev = NULL;
    if(root!=NULL)
    {
        if(!isBST3(root->left)) return 0;
        if(prev!=NULL && root->data <= prev->data) return 0;
        prev = root;
        return(isBST3(root->right));
    }
    return 1;
}

Node* search(Node* root, int key)
{
    if(root==NULL) return NULL;
    if(root->data == key)
        return root;
    if(root->data > key)
        return search(root->left, key);
    return search(root->right, key);
}

Node* search_itr(Node* root, int key)
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

void insert(Node* root, int key)
{
    // WRONG METHOD
    Node *prev = NULL;
    while(root!=NULL)
    {
        prev = root;
        if(root->data == key) return;
        if(root->data > key)
            root = root->left;
        if(root->data < key)
            root = root->right;
    }
    if(prev->data < key) prev->right = create(key);
    else prev->left = create(key);
}

Node* insert2(Node *root, int key)
{
    if(!root)
    {
        root = create(key);
        return root;
    }
    if(key > root->data)
        root->right = insert2(root->right, key);
    else
        root->left = insert2(root->left, key);
    return root;
}

Node* inOrderPredecessor(Node* root)
{
    root = root->left;
    while(root->right != NULL)
        root = root->right;
    return root;
}

Node *deleteNode(Node *root, int key)
{
    if(root == NULL) return NULL;
    if(root->left==NULL && root->right == NULL)
    {
        delete(root);
        return NULL;
    }
    if(root->data > key)
        deleteNode(root->left, key);
    else if(root->data < key)
        deleteNode(root->right, key);
    else
    {
        Node* iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

Node* deletion(Node* root, int key)
{
    if(root==NULL) return NULL;
    if(root->left == NULL && root->right == NULL)
    {
        if(root->data == key) return NULL;
        return root;
    }
    Node *current = NULL;
    Node *temp, *last;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        temp = Q.front();
        Q.pop();
        if(temp->data == key)
            current = temp;
        if(temp->left)
        {
            last = temp;
            Q.push(temp->left);
        }
        if(temp->right)
        {
            last = temp;
            Q.push(temp->right);
        }
    }
    if(current!=NULL)
    {
        current->data=temp->data;//replacing key_node's data to deepest node's data
        if(last->right==temp)
            last->right=NULL;
        else
            last->left=NULL;
        delete(temp);
    }
    return root;
}

Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

Node* Delete(Node* root, int key)
{
    if(root==NULL) return NULL;
    else if(root->data > key) root->left = Delete(root->left, key);
    else if(root->data < key) root->right = Delete(root->right, key);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root = NULL;
        }
        else if(root->left==NULL)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    Node *ROOT = NULL;
    ROOT = create(50);
    ROOT->left = create(25);
    ROOT->right = create(75);
    (ROOT->left)->left = create(15);
    (ROOT->left)->right = create(30);
    (ROOT->right)->left = create(65);
    (ROOT->right)->right = create(100);
    insert2(ROOT, 70);

    Node *found = search_itr(ROOT, 25);
    if(found) cout << "Found : " << found->data <<'\n';
    else cout << "Not Found\n";
    
    inordertraversal(ROOT);

    // ROOT = create(4);
    // ROOT->left = create(2);
    // ROOT->right = create(5);
    // (ROOT->left)->left = create(1);
    // (ROOT->left)->right = create(3);
    // cout << isBST3(ROOT);

    // deletion(ROOT, 30);
    cout << endl;
    Delete(ROOT, 50);
    inordertraversal(ROOT);

    return 69;
}
