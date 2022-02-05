#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string A, int a, string B, int b)
{
    if(a==0 || b==0) return 0;
    if(A[a-1]==B[b-1]) return 1+LongestCommonSubsequence(A, a-1, B, b-1);
    else return max(LongestCommonSubsequence(A, a-1, B, b), LongestCommonSubsequence(A, a, B, b-1));
}

int main()
{
    string X, Y;
    cin >> X >> Y;
    cout << LongestCommonSubsequence(X, X.size(), Y, Y.size());
    return 69;
}