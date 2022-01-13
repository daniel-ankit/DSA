#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countsubsets(vector<int> nums, int sum)
{
    int n = nums.size();
    vector<vector<int>> DP (n+1, (vector<int>(sum+1, 0)));

    for(int i=0; i<=n; i++) DP[i][0] = 1;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(nums[i-1]<=j)
                DP[i][j] = DP[i-1][j] + DP[i-1][j-nums[i-1]];
            else DP[i][j] = DP[i-1][j];
        }
    }
    return DP[n][sum];
}

int main()
{
    vector<int> nums = {2, 3, 5, 6, 8, 10};
    cout << countsubsets(nums, 10);
    return 69;
}
