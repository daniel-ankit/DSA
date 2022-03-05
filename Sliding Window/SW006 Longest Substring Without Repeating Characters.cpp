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
    int lengthOfLongestSubstring(string s)
    {
        if(s.length()==0 || s.length()==1) return s.length();
        deque <char> S;
        int ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            while(count(S.begin(), S.end(), s[i])!=0)
                S.pop_front();
            S.push_back(s[i]);
            if(S.size() > ans) ans = S.size();
        }
        return ans;
    }
};

int main()
{
    Solution object;
    
    return 69;
}