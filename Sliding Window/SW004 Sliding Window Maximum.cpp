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
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> ans;
        deque<int> Q;
        for(int i=0; i<k; i++)
        {
            if(Q.empty())
            {
                Q.push_back(i);
                continue;
            }
            while(!Q.empty() && nums[Q.back()]<=nums[i])
                Q.pop_back();
            Q.push_back(i);
        }
        ans.push_back(nums[Q.front()]);
        
        for(int i=k; i<nums.size(); i++)
        {
            if(Q.front()==i-k)
                Q.pop_front();
            while(!Q.empty() && nums[Q.back()]<nums[i])
                Q.pop_back();
            Q.push_back(i);
            ans.push_back(nums[Q.front()]);
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = object.maxSlidingWindow(nums, k);
    for(auto x:ans)
        cout << x << " ";
    return 69;
}