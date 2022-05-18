// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[501][501];
    int solve(int row, int col, vector<vector<int>>& grid, int N){
        if(row >= N || col < 0 || col >= N) return INT_MIN;
        if(row == N - 1) return grid[row][col];
        if(dp[row][col] != -1) return dp[row][col];
        
        return dp[row][col] = grid[row][col] + max(max(solve(row + 1, col, grid, N),
        solve(row + 1, col - 1, grid, N)), solve(row + 1, col + 1, grid, N));
    }

    int maximumPath(int N, vector<vector<int>> grid){
        
        // if(N == 1) return grid[0][0];
        
        // int temp = 0;
        // int ind = 0;
        // for(int i=0;i<N;i++){
        //     if(grid[0][i] > temp){
        //         temp = grid[0][i];
        //         ind = i;
        //     }
        // }
        // int ans = INT_MIN;
        
        // memset(dp, -1, sizeof(dp));
        // ans = max(ans, solve(0, ind, grid, N));
        
        // memset(dp, -1, sizeof(dp));
        // ans = max(ans, solve(0, N/2 - 1, grid, N));
        
        // memset(dp, -1, sizeof(dp));
        // ans = max(ans, solve(0, N/2, grid, N
        
        int ans = INT_MIN;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<N;i++){
            ans = max(ans, solve(0,i,grid, N));
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends