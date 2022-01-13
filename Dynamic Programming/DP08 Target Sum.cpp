#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int targetsum(vector<int> nums, int target)
{
    int find = (target + accumulate(nums.begin(), nums.end(), 0))/2;
    int n = nums.size();
    vector<vector<int>> DP (n+1, vector<int>(find+1, 0));
    for(int i=0; i<=n; i++) DP[i][0] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=find; j++)
        {
            if(nums[i-1]<=j)
                DP[i][j] = DP[i-1][j] + DP[i-1][j-nums[i-1]];
            else DP[i][j] = DP[i-1][j];
        }
    }
    return DP[n][find];
}

int main()
{
    vector<int> nums = {2, 4, 6, 8, 10};
    cout << targetsum(nums, 6);
    return 69;
}