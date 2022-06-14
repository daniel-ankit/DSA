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
    int MinDeletions(string text1) {
        string text2 = text1;
        reverse(text2.begin(), text2.end());
        int a = text1.size();
        int dp[a+1][a+1];
        for(int i=0; i<=a; i++)
        {
            for(int j=0; j<=a; j++)
            {
                if(i==0 || j==0) dp[i][j] = 0;
                else if(text1[i-1]==text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return a-dp[a][a];
    }
};

int main()
{
    Solution object;
    string X;
    cin >> X;
    cout << object. MinDeletions(X);
    return 69;
}