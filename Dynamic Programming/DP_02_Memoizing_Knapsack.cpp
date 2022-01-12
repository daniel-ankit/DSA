#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define MAX 1001 // From given constraints.

int knapsack(vector<int> weight, vector<int> value, int W, int index)
{
    static vector<vector<int>> DP (MAX, vector<int> (MAX, -1)); // Static 2D array.

    if(W<=0 || index<0)
        return 0;

    if(DP[W][index]==-1)
    {
        if(weight[index]<=W)
            DP[W][index] = max(value[index]+knapsack(weight, value, W-weight[index], index-1), knapsack(weight, value, W, index-1));
        else
            DP[W][index] = knapsack(weight, value, W, index-1);
    }
    return DP[W][index];
}

int main()
{
    int N;
    cout << "Total Number of items : ";
    cin >> N;
    
    int W;
    cout << "Capacity of Knapsack : ";
    cin >> W;

    vector<int> weight(N), value(N);

    cout << "Enter the weights : ";
    for(int i=0; i<N; i++)
        cin >> weight[i];

    cout << "Enter the values : ";
    for(int i=0; i<N; i++)
        cin >> value[i];
    
    cout << "Maximum value we can store in the knapsack is : " << knapsack(weight, value, W, N-1);
    return 69;
}