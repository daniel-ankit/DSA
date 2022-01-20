#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int max_profit(vector<int> length, vector<int> prices, int L, int n)
    {
        int DP[L+1][n+1] = {-1};
        for(int i=0; i<=n; i++) DP[i][0] = 0;
        for(int i=0; i<=L; i++) DP[0][i] = 0;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=L; j++)
            {
                if(length[i-1]<=j)
                    DP[i][j] = max(prices[i-1] + DP[i][j-length[i-1]], DP[i-1][j]);
                else DP[i][j] = DP[i-1][j];
            }
        }
        return DP[n][L];
    }
};

int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> val(N), wt(N);
    for(int i = 0;i < N;i++)
        cin >> val[i];
    for(int i = 0;i < N;i++)
        cin >> wt[i];
        
    Solution ob;
    cout << ob.max_profit(wt, val, W, N) << endl;
    return 69;
}