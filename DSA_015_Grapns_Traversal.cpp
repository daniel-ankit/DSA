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
bool Visited[10] ={0};

void link(int a, int b)
{
    M[a][b]=1;
    M[b][a]=1;
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
    link(8, 9);
    link(9, 7);
    link(9, 0);
    link(9, 4);
    link(7, 1);
    link(7, 2);
    link(7, 3);
    link(7, 6);
    link(1, 2);
    link(2, 3);
    link(2, 4);
    link(3, 4);
    link(4, 5);
    link(4, 0);
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

void BFS(int starting_Node)
{
    queue <int> Q;
    bool Visited[N] = {0};
    cout << starting_Node <<" ";
    Q.push(starting_Node);
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

void DFS(int Starting_Node)
{
    cout << Starting_Node << " ";
    Visited[Starting_Node] = 1;
    for(int j=0; j<N; j++)
    {
        if(M[Starting_Node][j]==1 && !Visited[j])
            DFS(j);
    }
}

int main()
{
    IntiateLinks();
    printmatrix();
    // set <int> V = BFS();
    // for(auto x: V)
    //     cout << x << " ";
    BFS(2);
    DFS(8);
    return 69;
}