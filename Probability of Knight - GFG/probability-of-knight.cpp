// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	double solve(int x, int y, int n, int k, vector<vector<vector<double>>> &dp){
	    if(x >= n || y >= n || x < 0 || y < 0) return 0;
	    if(dp[x][y][k] != -1) return dp[x][y][k];
	    if(k == 0) return 1;
	    
	    double ans = 0;
	    for(int i=0;i<8;i++) ans += solve(x + dx[i], y + dy[i], n, k - 1, dp)/8.0;
	    return dp[x][y][k] = ans;
	}
	
	double findProb(int N,int start_x, int start_y, int steps)
	{
	    vector<vector<vector<double>>>dp(N + 1, vector<vector<double>>(N + 1, vector<double>(steps + 1, -1)));
	    return solve(start_x, start_y, N, steps, dp);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends