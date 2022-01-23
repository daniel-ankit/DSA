#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &V, int temp)
{
    if(V.size()==0 || V[V.size()-1]<=temp)
    {
        V.push_back(temp);
        return;
    }
    int val = V[V.size()-1];
    V.pop_back();
    insert(V, temp);
    V.push_back(val);
    return;
}

void Sort(vector<int> &V)
{
    if(V.size()==0) return;
    int temp = V[V.size()-1];
    V.pop_back();
    Sort(V);
    insert(V, temp);
}

int main()
{
    vector<int> V = {1, 2, 9, 8, 1, 2, 4, 5, 5};
    Sort(V);
    for(auto x: V)
        cout << x << " ";
    return 69;
}
