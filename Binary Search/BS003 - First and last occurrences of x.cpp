//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int i=0, j=n-1;
    int first = -1, last = -1;
    while(i<=j)
    {
        int mid = i+(j-i)/2;
        if(arr[mid]==x) first = mid;
        if(arr[mid]>=x) j = mid-1;
        else i = mid+1;
    }
    i=0, j=n-1;
    while(i<=j)
    {
        int mid = i+(j-i)/2;
        if(arr[mid]==x) last = mid;
        if(arr[mid]<=x)i = mid+1;
        else j = mid-1;
    }
    return {first, last};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends