#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> V;
    void push(int x)
    {
        V.push_back(x);
        int index = V.size()-1;
        while(1)
        {
            int swapi;
            (index%2==0) ? (swapi = index/2-1) : (swapi = index/2);
            if(V[swapi]<V[index])
            {
                swap(V[index], V[swapi]);
                index = swapi;
            }
            else return;
            if(index<=0) return;
        }
    }
    void pop()
    {
        int index = 0;
        V[0] = INT_MIN;
        while(1)
        {
            int L = index*2+1, R = index*2+2 ;
            if(V[L]>V[R] && V[index]<V[L])
            {
                swap(V[L], V[index]);
                index = L;
            }
            else if(V[R]>V[L] && V[index]<V[R])
            {
                swap(V[R], V[index]);
                index = R;
            }
            if(index+1 >= V.size() || (V[index]>=V[L] && V[index]>=V[R]))
            {
                V.pop_back();
                return;
            }
        }
    }
    int top()
    {
        if (V.size() == 0)
            return INT_MIN;
        else
            return V[0];
    }
    bool empty()
    {
        return (V.size() == 0);
    }
    void print()
    {
        for(auto x:V)
            cout << x << " ";
        cout << endl;
    }
};


int main()
{
    MaxHeap heap;
    heap.push(1);
    heap.push(2);
    heap.push(3);
    heap.push(4);
    heap.push(5);
    heap.push(6);
    heap.push(7);
    heap.push(8);
    heap.push(9);
    heap.push(10);
    heap.push(11);
    heap.print();
    heap.pop();
    while (!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
    return 69;
}