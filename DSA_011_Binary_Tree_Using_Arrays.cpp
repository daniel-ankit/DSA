#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char tree[100];

void root(char ch)
{
    if(tree[0]=='\0')
    {
        memset(tree, '-', 100);
        tree[0]=ch;
    }
    else 
    cout << "Root is taken \n";
}

void set_left(int at, char ch)
{
    at--;
    if(tree[at]=='-')
    cout << "Parent node isn't present \n";
    else
    {
        if(tree[2*at+1]!='-')
        cout << "Value of left node of " << at+1 << " changed from " << tree[2*at+1] << " to " << ch << '\n';
        else cout << "Left node of " << at+1 << " set to: " << ch << endl;
        tree[2*at+1]=ch;
    }
}

void set_right(int at, char ch)
{
    at--;
    if(tree[at]=='-')
    cout << "Parent node isn't present \n";
    else
    {
        if(tree[2*at+2]!='-')
        cout << "Value of right node of " << at+1 << " changed from " << tree[2*at+2] << " to " << ch << '\n';
        else cout << "Right node of " << at+1 << " set to: " << ch << endl;
        tree[2*at+2]=ch;
    }
}

int main()
{
    root('A');
    set_left(1, 'D');
    set_right(1, 'M');
    set_left(1, 'B');
    set_right(1, 'C');
    set_left(2, 'D');
    set_right(2, 'E');
    set_left(3, 'F');
    set_right(3, 'G');
    set_left(4, 'H');
    set_right(7, 'I');
    set_right(14, 'M');
    set_right(15, 'Z');
    for(int i=0; i<32; i++)
    {
        cout << tree[i] << " ";
    }
    return 69;
}