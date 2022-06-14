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

class Solution {
public:
    string PrintLCS(string A, string B)
    {
        int a = A.size(), b = B.size();
        int dp[a+1][b+1];
        string ans = "";
        for(int i=0; i<=a; i++) dp[i][0] = 0;
        for(int i=0; i<=b; i++) dp[0][i] = 0; 
        for(int i=1; i<=a; i++)
        {
            for(int j=1; j<=b; j++)
            {
                if(A[i-1]==B[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans += A[i-1];
                }
                else dp[i][j] = 0;
            }
        }
        return ans;
    }
};

int main()
{
    Solution object;
    cout << object.PrintLCS("abcdf", "abxyzcf");
    return 69;
}