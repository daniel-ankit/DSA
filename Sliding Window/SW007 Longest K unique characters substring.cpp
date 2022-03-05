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
    int longestKSubstr(string s, int k) {
    map<char, int> M;
        int j = 0, i = 0;
        int ans = -1;
        while(j<s.size())
        {
            M[s[j]]++;
            if(M.size()==k)
                ans = max(ans, j-i+1);
            else if(M.size()>k)
            {
                while(M.size()>k)
                {
                    M[s[i]]--;
                    if(M[s[i]]==0) M.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};

int main()
{
    Solution object;
    
    return 69;
}