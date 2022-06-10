#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string A, int a, string B, int b)
{
    static vector<vector<int>> DP(a+1,vector<int>(b+1, -1));
    if(a==0 || b==0) return 0;
    if(DP[a][b]!=-1) return DP[a][b];
    if(A[a-1] == B[b-1])
        DP[a][b] = 1 + LongestCommonSubsequence(A, a-1, B, b-1);
    else DP[a][b] = max(LongestCommonSubsequence(A, a-1, B, b), LongestCommonSubsequence(A, a, B, b-1));
    return DP[a][b];
}

int main()
{
    string X, Y;
    cin >> X >> Y;
    cout << LongestCommonSubsequence(X, X.size(), Y, Y.size());
    return 69;
}