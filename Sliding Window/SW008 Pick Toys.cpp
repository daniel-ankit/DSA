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
    int totalFruit(vector<int>& toys) {
        map<int, int> M;
        int ans = 0;
        int j = 0;
        for(int i=0; i<toys.size(); i++)
        {
            M[toys[i]]++;
            if(M.size()>2)
            {
                while(M.size()>2)
                {
                    M[toys[j]]--;
                    if(M[toys[j]]==0) M.erase(toys[j]);
                    j++;
                }
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};

int main()
{
    Solution object;
    
    return 69;
}