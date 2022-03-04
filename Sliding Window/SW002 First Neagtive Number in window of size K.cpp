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
    vector<int> firstnegative(vector<int> nums, int k)
    {
        deque<int> neg;
        vector<int> ans;
        int j = 0;
        for(int i=0; i<k; i++)
        {
            if(nums[i]<0)
                neg.push_back(i);
        }
        (neg.empty()) ? (ans.push_back(0)) : (ans.push_back(nums[neg.front()]));
        for(int i=k; i<nums.size(); i++)
        {
            if(nums[i]<0)
                neg.push_back(i);
            if(!neg.empty() && i-k == neg.front()) neg.pop_front();
            (neg.empty()) ? (ans.push_back(0)) : (ans.push_back(nums[neg.front()]));
        }
        return ans;
    }
};

int main()
{
    Solution object;
    vector<int> nums= {-4554, 7421, -210, -5412, -4210, -421, 23, 53, 895, 895, -79854, -74512};
    vector<int> ans = object.firstnegative(nums, 3);
    for(auto x:ans)
        cout << x << " ";
    return 69;
}