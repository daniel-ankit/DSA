#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int W, int index)
{
    if(W <= 0 || index < 0) // Base Condition
        return 0; 
    if(weight[index]<=W)
        return max(value[index]+knapsack(weight, value, W-weight[index], index-1), knapsack(weight, value, W, index-1));
    else
        return knapsack(weight, value, W, index-1);
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
