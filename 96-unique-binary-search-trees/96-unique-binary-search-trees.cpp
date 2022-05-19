class Solution {
public:
    
    int dp[20];
    int solve(int n){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int k=1;k<=n;k++) ans += solve(k - 1)*solve(n - k);
        return dp[n] = ans;
    }
    
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};