// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int t[10002][4];
    
    int solve(int idx, int arr[], int n){
        if(n == 0) return 0;
        if(idx == 0) return INT_MIN;
        if(t[n][idx]!=-1) return t[n][idx];
        
        if(arr[idx-1]<=n){
            return t[n][idx] = max(1 + solve(idx,arr, n - arr[idx-1]), solve(idx-1, arr, n));
        }
        else{
            return t[n][idx] = solve(idx-1, arr, n);
        }
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int arr[3];
        arr[0] = x, arr[1] = y, arr[2] = z;
        memset(t,-1,sizeof(t));
        return max(0,solve(3, arr, n));
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends