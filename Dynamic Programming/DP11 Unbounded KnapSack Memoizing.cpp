#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int max_profit(vector<int> weight, vector<int> value, int W, int n)
    {
        int DP[W+1][n+1] = {-1};
        for(int i=0; i<=n; i++) DP[i][0] = 0;
        for(int i=0; i<=W; i++) DP[0][i] = 0;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=W; j++)
            {
                if(weight[i-1]<=j)
                    DP[i][j] = max(value[i-1] + DP[i][j-weight[i-1]], DP[i-1][j]);
                else DP[i][j] = DP[i-1][j];
            }
        }
        return DP[n][W];
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