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

    //   O(n²) Time Complexity
    //   O(1) Auxiliary Space
    //   O(n) Swaps

    for(int i=0; i<V.size()-1; i++)
    {
        for(int j=0; j<V.size()-i-1; j++)
            if(V[j+1] < V[j]) swap(V[j+1], V[j]);
    }
}

void selectionsort(vector<int> &V)
{

    //   O(n²) Time Complexity
    //   O(1) Auxiliary Space
    //   O(n) Swaps

    int index, i, j;
    for(i=0; i<V.size()-1; i++)
    {
        index = i;
        for(j=i+1; j<V.size(); j++)
            if(V[j] < V[index]) index = j;
        swap(V[i], V[index]);
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
    int Sample[6] = {15, 20, 10, 0, 5, 0};
    vector<int> V;
    for(int i=0; i<6; i++)
        V.push_back(Sample[i]);

    selectionsort(V);
    print(V);
    return 69;
}