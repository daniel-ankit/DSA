#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long int MaxWays(vector<int> coins, int sum)
{
    long long int n = coins.size();
    vector<vector<long long int>> DP(n+1, vector<long long int>(sum+1, 0));
    for(int i=0; i<=n; i++) DP[i][0] = 1;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(coins[i-1]<=j)
                DP[i][j] = DP[i][j-coins[i-1]] + DP[i-1][j];
            else DP[i][j] = DP[i-1][j];
        }
    }
    return DP[n][sum];
};

int main()
{
    vector<int> coins = {1, 2, 3};
    int sum = 5;
    cout<< MaxWays(coins, sum);
    return 69;
}