class Solution {
public:
    
    int dp[60];
    int solve(int n){
        if(n <= 1) return 1;
        if(dp[n]!=-1) return dp[n];
        
        int ans = INT_MIN;
        for(int k=1;k<n;k++) ans = max(ans, k * max(solve(n - k), n - k));
        return dp[n] = ans;
    }
    
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};