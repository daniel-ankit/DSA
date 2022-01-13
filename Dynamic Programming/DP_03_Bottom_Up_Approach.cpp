#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int W, int n)
{
    static vector<vector<int>> DP (n+1, vector<int>(W+1, -1));
    for(int i=0; i<=n; i++) DP[i][0] = 0;
    for(int i=0; i<=W; i++) DP[0][i] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=W; j++)
        {
            if(weight[i-1]<=j)
                DP[i][j] = max(value[i-1]+DP[i-1][j-weight[i-1]], DP[i-1][j]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }
    return DP[n][W];
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