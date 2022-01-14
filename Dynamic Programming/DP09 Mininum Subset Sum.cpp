#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumsbsetsum(vector<int> nums)
{
    int total = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
    vector<vector<int>> DP (n+1, vector<int>(total+1, 0));
    for(int i=0; i<=n; i++) DP[i][0] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=total; j++)
        {
            if(nums[i-1]<=j)
                DP[i][j] = max(DP[i-1][j-nums[i-1]], DP[i-1][j]);
            else DP[i][j] = DP[i-1][j];
        }
    }
    int ans = 0;
    for(int i=total/2; i>=0; i--)
    {
        if(DP[n][i]==1)
        {
            ans = i;
            break;
        }
    }
    return total-(2*ans);
}

int main()
{
    vector<int> nums = {1, 2, 7};
    cout << minimumsbsetsum(nums); 
    return 69;
}