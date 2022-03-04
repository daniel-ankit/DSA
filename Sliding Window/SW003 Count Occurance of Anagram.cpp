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
	int search(string pat, string txt) {
	    vector<int> cmp(26, 0), save(26, 0);
	    for(int i=0; i<pat.size(); i++)
	    {
	        cmp[txt[i]-'a']++;
	        save[pat[i]-'a']++;
	    }
	    int count = 0;
	    if(save==cmp) count++;
	    for(int i=pat.size(); i<txt.size(); i++)
	    {
	        cmp[txt[i]-'a']++;
	        cmp[txt[i-pat.size()]-'a']--;
	        if(save == cmp) count++;
	    }
	    return count;
	}

};

int main()
{
    Solution object;
    cout << object.search("for", "forxoxofroxoxoxofr");
    return 69;
}