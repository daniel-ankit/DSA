#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool equalsumpartiton(vector<int> nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
    if(sum%2)
        return false;
    sum/=2;
    vector<vector<int>> DP(n+1, (vector<int>(sum+1, -1)));

    for(int i=0; i<=n; i++) DP[i][0] = 1;
    for(int i=1; i<=sum/2; i++) DP[0][i] = 0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=sum; j++)
        if(nums[i-1]<=j)
            DP[i][j] = max(DP[i-1][j-nums[i-1]], DP[i-1][j]);
        else DP[i][j] = DP[i-1][j];
    }
    return DP[n][sum]==true;
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << equalsumpartiton(nums);
    return 69;
}