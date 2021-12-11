#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &V)
{
    for(auto x : V)
        cout << x << " ";
    cout << endl;
}

void bubblesort(vector<int> &V)
{
    for(int i=0; i<V.size(); i++)
    {
        for(int j=i; j<V.size(); j++)
            if(V[i]>V[j]) swap(V[i], V[j]);
    }
}

void insertionsort(vector<int> &V)
{
    
}

void quicksort(vector<int> &V)
{

}

void mergesort(vector<int> &V)
{

}

void countsort(vector<int> &V)
{

}

int main()
{
    int Sample[5] = {15, 20, 10, 0, 5};
    vector<int> V;
    for(int i=0; i<5; i++)
        V.push_back(Sample[i]);

    bubblesort(V);
    print(V);
    return 69;
}