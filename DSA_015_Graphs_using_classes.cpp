#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    public:
    int N=0;
    bool **M;
    bool *Visited;
    Graph(int n)
    {
        this->N = n;
        M = new bool*[n];
        for(int i=0; i<n; i++)
        {
            M[i] = new bool[n];
            memset(M[i], 0, n);
        }
        Visited = new bool[n];
        memset(Visited, 0, n);
    }
    void link(int a, int b) { M[a][b]=1; M[b][a]=1; }
    void print()
    {
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
    }
    void BFS(int starting)
    {
        queue <int> Q;
        Q.push(starting);
        bool V[10] ={0};
        V[starting]=1;
        while(!Q.empty())
        {
            int front = Q.front();
            cout << front << " ";
            Q.pop();
            for(int i=0; i<N; i++)
            {
                if(M[front][i]==1 && V[i]==0)
                {
                    V[i] = 1;
                    Q.push(i);
                }
            }
        }
        cout << endl;
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
};

int main()
{
    Graph G(6);
    G.link(0, 4);
    G.link(2, 0);
    G.link(1, 2);
    G.link(1, 3);
    G.link(2, 3);
    G.link(4, 3);
    G.BFS(2);
    // G.print();
    G.DFS(2);
    return 69;
}