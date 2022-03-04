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
    int maxsumsubarray(vector<int> nums, int k)
    {
        int sum = 0;
        for(int i=0; i<k; i++)
            sum += nums[i];
        int maxx = sum;
        for(int i=k; i<nums.size(); i++)
        {
            sum += nums[i]-nums[i-k];
            maxx = max(maxx, sum);
        }
        return maxx;
    }
};

int main()
{
    Solution object;
    vector<int> nums = {2, 5, 1, 8, 2, 9, 1};
    cout << object.maxsumsubarray(nums, 3);
    return 69;
}