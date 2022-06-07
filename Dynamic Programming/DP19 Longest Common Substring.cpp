#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int maxx = 0;
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        for(int i=0; i<=m; i++)
            dp[0][i] = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = 0;
                maxx = max(maxx, dp[i][j]);
            }
        }
        return maxx;
    }
};

int main()
{
    Solution object;
    
    return 69;
}