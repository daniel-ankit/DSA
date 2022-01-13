#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countsubsets(vector<int>nums, int diff)
{
    int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
    int find = (diff + sum)/2;
    vector<vector<int>> DP (n+1, (vector<int>(find+1,0)));

    for(int i=0; i<=n; i++) DP[i][0] = 1;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=find; j++)
        {
            if(nums[i-1]<=j)
                DP[i][j] = DP[i-1][j-nums[i-1]] + DP[i-1][j];
            else DP[i][j] = DP[i-1][j];
        }
    }
    return DP[n][find];
}

int main()
{
    vector<int> nums = {2, 3, 5, 6, 8, 10};
    cout << countsubsets(nums, 10);
    return 69;
}
