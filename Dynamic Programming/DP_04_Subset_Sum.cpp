#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool subset_present(vector<int> nums, int sum)
{
    int n = nums.size();
    vector<vector<bool>>DP (n+1, vector<bool>(sum+1));

    for(int i=0; i<=n; i++) DP[i][0] = 1;
    for(int j=1; j<=sum; j++) DP[0][j] = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(nums[i-1]<=j)
                DP[i][j] = max(DP[i-1][j-nums[i-1]], DP[i-1][j]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }
    return DP[n][sum];
}  

int main()
{
    vector<int> nums = {2, 4, 9, 8, 3};
    int sum = 11;
    cout << subset_present(nums, sum);
    return 69;
}