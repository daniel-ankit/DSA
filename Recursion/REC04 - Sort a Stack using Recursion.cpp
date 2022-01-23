#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &S, int temp)
{
    if(S.empty() || S.top()>=temp)
    {
        S.push(temp);
        return;
    }
    int val = S.top();
    S.pop();
    insert(S, temp);
    S.push(val);
    return;
}

void Sort(stack<int> &S)
{
    if(S.empty()) return;
    int temp = S.top();
    S.pop();
    Sort(S);
    insert(S, temp);
}


int main()
{
    stack <int> S;
    S.push(1);
    S.push(2);
    S.push(9);
    S.push(8);
    S.push(1);
    S.push(2);
    S.push(4);
    S.push(5);
    S.push(5);
    Sort(S);
    while(!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
    return 69;
}