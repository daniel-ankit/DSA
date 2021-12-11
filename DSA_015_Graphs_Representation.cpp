#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*

REPRESENTATION OF GRPAHS
- Adjacency List
- Ajacency Matrix
- Edge Set
- Compact List representation
- Cost Adjacency List
- Cost Adjacency Matrix

*/

void add(vector <int> V[], vector<pair<int, int>> &P, int a, int b)
{
    V[a].push_back(b);
    V[b].push_back(a);
    P.push_back(make_pair(a, b));
}

void printlist(vector<int> V[], int S)
{
    cout << "Adjacency List Method :" << endl;
    for(int i=0; i<S; i++)
    {
        cout << i << " -> ";
        for(auto x : V[i])
            cout << x << " ";
        cout << endl;
    }
}

void printmatrix(vector<int> V[], int S)
{
    cout << "Adjacency Matrix Method :" << endl;
    for(int i=0; i<5; i++)
    {
        sort(V[i].begin(), V[i].end());
        for(int j=0, k=0; j<5, k<5; k++)
        {
            if(V[i][j]==k)
            {
                cout << "1 ";
                j++;
            }
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void printpair(vector<pair<int, int>> P)
{
    cout << "Edge Pair Method :" << endl; 
    for(auto x : P)
    cout << x.first << " -> " << x.second << endl;
}

int main()
{
    vector <int> V[5];
    vector<pair<int, int>> P;
    add(V, P, 0, 1);
    add(V, P, 2, 4);
    add(V, P, 1, 2);
    add(V, P, 2, 3);
    add(V, P, 3, 4);
    add(V, P, 4, 0);
    printlist(V, 5);
    cout << endl;
    printmatrix(V, 5);
    cout << endl;
    printpair(P);
    return 69;
}