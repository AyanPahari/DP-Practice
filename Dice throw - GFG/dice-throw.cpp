// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    long long dp[51][51];
    long long solve(int n, int k, int target){
        if(n == 0){
            if(target == 0) return 1;
            else return 0;
        }
        if(dp[n][target] != -1) return dp[n][target];
        
        long long ans = 0;
        for(int i=1;i<=k;i++){
            if(i > target) continue;
            ans += solve(n-1, k, target - i);
        }
        return dp[n][target] = ans;
    }
  
    long long noOfWays(int M , int N , int X) {
        memset(dp,-1,sizeof(dp));
        return solve(N,M,X);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}  // } Driver Code Ends