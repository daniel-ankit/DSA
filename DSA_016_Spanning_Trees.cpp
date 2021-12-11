#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*  THEORY

SUBGRAPH : A subgraph S of graph G is a graph whose vertices and edges are subsets of the original graphn G.
CONNECTED GRAPH : Graph that is connected in the sense of a topological space.
COMPLETE GRAPH : Undirected Graph in which every pair of distinct vertices are connected.

SPANNING TREE : A connected Subgraph S og graph G is said to be spanning tree if
    - All vertices are present in the subgraph
    - Number of edges = Number of vertices - 1
    - Total Number of Spanning trees for a graph : n⁽ⁿ⁻²⁾.
*/

class Graph
{
    public :
    int N=0;
    int **M;
    bool *V;
    Graph(int n)
    {
        this->N = n;
        M = new int*[n];
        for(int i=0; i<n; i++)
        {
            M[i] = new int[n];
            for(int j=0; j<N; j++)
                M[i][j] = -1;
        }
        V = new bool[n];
        memset(V, 0, n);
    }
    void link(int a, int b, int cost)
    {
        M[a][b] = cost;
        M[b][a] = cost;
    }
    void printmatrix()
    {
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
                cout << setw(2) << M[i][j] << " ";
            cout << endl;
        }
    }
    void minimumcost(int Starting_Node)
    {
        
    }
};

int main()
{
    Graph G(4);
    G.link(0, 1, 2);
    G.link(0, 2, 3);
    G.link(0, 3, 6);
    G.link(1, 2, 8);
    G.link(1, 3, 1);
    G.link(2, 3, 15);
    G.printmatrix();

    return 69;
}