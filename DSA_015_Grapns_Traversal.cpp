#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*   THEORY

GRAPH TRAVERSAL ALGORITHMS ARE:
- Breadth First Search (BFS)
    Implementation using Queue

- Depth First Search (DFS)
    Implementation using Stack

*/

int N = 10;
bool M[10][10] = {0};

void link(int a, int b)
{
    M[a][b]=1;
}

void printmatrix()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

void IntiateLinks()
{
    link(7, 1);
    link(7, 2);
    link(7, 3);
    link(1, 2);
    link(1, 7);
    link(2, 1);
    link(2, 7);
    link(2, 3);
    link(7, 6);
    link(3, 2);
    link(3, 4);
    link(4, 2);
    link(4, 3);
    link(4, 5);
    link(4, 0);
    link(5, 4);
    link(0, 4);
    link(9, 7);
    link(9, 0);
    link(4, 9);
    link(8, 9);
}

set<int> BFS()
{
    set <int> V;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(M[i][j]==1)
            V.insert(j);
        }
    }
    return V;
}

void BFSQ(int starting_Node)
{
    queue <int> Q;
    cout << starting_Node <<" ";
    Q.push(starting_Node);
    bool Visited[N]={0}; // Initially all vertices are unvisited
    Visited[starting_Node] = true; // First given vertice is assumed to be present
    while(!Q.empty())
    {
        int front = Q.front();
        Q.pop();
        for(int i=0; i<N; i++)
        {
            if(M[front][i]==1 && Visited[i]==0)
            {
                Visited[i] = true; // Declaring vertices as visited.
                cout << i << " "; // Printing Visited vertice
                Q.push(i);
            }
        }
    }
}

void DFSS(int Starting_Node)
{

}

int main()
{
    IntiateLinks();
    printmatrix();
    set <int> V = BFS();
    set <int> :: iterator it;
    for(it = V.begin(); it!=V.end(); it++)
        cout << *it << " ";
    BFSQ(2);
    return 69;
}