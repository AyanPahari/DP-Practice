// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    int dp[1001][1001];
    int solve(int i, int j, vector<vector<int>> &grid){
        if(i >= grid.size() || j >= grid[0].size()) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        
        int height = min(solve(i + 1, j, grid), solve(i, j + 1, grid));
        
        if(height == INT_MAX) height = 1;
        int res = 0;
        if(height - grid[i][j] > 0) res = height - grid[i][j];
        else res = 1;
        
        return dp[i][j] = res;
    }
    
    int minPoints(vector<vector<int>> points, int M, int N) 
    { 
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, points);
    } 
};


// { Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(a, m, n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends