#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  THEORY

SEARCHING ALGORITHMS

    - Linear Search
        - Sequencial Approach
        - For unsorted arrays or lists
        - Time complexity O(n)
        - Efficient for small size data sets

    - Binary Search
        - Devide and Conquer Approach
        - For sorted arrays or lists
        - Time complexity O(logn)
        - Efficient for large size data sets

*/

bool LinearSearch(vector<int> V, int key)
{
    for(int i=0; i<V.size(); i++)
        if(V[i]==key) return 1;
    return 0;
}

bool BinarySearch(vector<int> V, int key)
{
    int i = 0, j = V.size()-1;
    while(i<=j)
    {
        int m = (i+j)/2;
        if(key==V[m])
            return 1;
        (key > V[m]) ? (i = m+1) : (j = m-1);
    }
    return 0;
}

bool BinarySearch(vector<int> V, int i, int j, int key)
{
    while(i<=j)
    {
        int m = i + (j-i)/2;
        if(V[m]==key) return 1;
        if(V[m] > key) return BinarySearch(V, i, m-1, key);
        return BinarySearch(V, m+1, j, key);
    }
    return 0;
}

int main()
{
    int Sample[5] = {15, 20, 10, 0, 5};
    vector<int> V;
    for(int i=0; i<5; i++)
        V.push_back(Sample[i]);
    cout << LinearSearch(V, 10);
    sort(V.begin(), V.end());
    cout << BinarySearch(V, 10);
    cout << BinarySearch(V, 0, V.size(), 5);
    return 69;
}