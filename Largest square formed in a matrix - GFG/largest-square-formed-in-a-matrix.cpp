// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // int dp[51][51];
    // int solve(int i, int j, vector<vector<int>> &mat){
    //     if(i >= mat.size() || j >= mat[0].size() || mat[i][j] == 0) return 0;
    //     int ans = 1 + min(min(solve(i, j + 1, mat),solve(i + 1, j, mat)),solve(i + 1, j + 1, mat));
    //     return dp[i][j] = ans;
    // }

    int maxSquare(int n, int m, vector<vector<int>> mat){
        // int maxi = 0;
        // memset(dp, -1, sizeof(dp));
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(mat[i][j] == 1) maxi = max(maxi, solve(i, j, mat));
        //     }
        // }
        // return maxi;
        for(int i=1;i<n;i++){
           for(int j=1;j<m;j++)
               if(mat[i][j]) mat[i][j]+=min(mat[i-1][j],min(mat[i][j-1],mat[i-1][j-1]));
       }
       int h=0;
       for(auto i:mat)
           for(auto j:i) h=max(h,j);
       return h;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends