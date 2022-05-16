// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	int mod = 1e9 + 7;
	int dp[100001];
	
	int solve(int n, int m){
	    if(n < m) return 1;
	    if(n == m) return 2;
	    if(dp[n]!=-1) return dp[n];
	    return dp[n] = (solve(n-1,m) % mod + solve(n-m,m) % mod) % mod;
	}
	
	int countWays(int n, int m){
	   memset(dp, -1, sizeof(dp));
	   return solve(n,m);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends