#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_profit(int L, vector<int> length, vector<int> price, int n)
{
    int DP[n+1][L+1] = {-1};
    for(int i=0; i<=n; i++) DP[0][i] = 0;
    for(int i=0; i<=L; i++) DP[i][0] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=L; j++)
        {
            if(length[i-1]<=j)
                DP[i][j] = max(price[i-1]+DP[i][j-length[i-1]], DP[i-1][j]);
            else DP[i][j] = DP[i-1][j];
        }
    }
    return DP[n][L];
}

int main()
{
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << max_profit(8, length, price, 8);
    return 69;
}