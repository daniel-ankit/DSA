// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N)
    {
        string S = "";
        while(N)
        {
            if(N%2) S.push_back('1');
            else S.push_back('0');
            N/=2;
        }
        // cout << S;
        int save = -1;
        bool found = 0;
        for(int i=0; i<S.length(); i++)
        {
            if(S[i]=='1' && found==0)
            {
                save = i;
                found = 1;
                continue;
            }
            if(found==1 && S[i]=='1') return -1;
        }
        return (save==-1) ? (save) : (save+1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends