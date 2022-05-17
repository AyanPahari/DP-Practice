class Solution {
public:
    
    int dp[60];
    int solve(int n){
        // if(n <= 1) return 1;
        // if(dp[n]!=-1) return dp[n];
        dp[0] = 1, dp[1] = 1;
        
        int ans = INT_MIN;
        for(int i=2;i<=n;i++){
            for(int k=1;k<i;k++) ans = max(ans, k * max(dp[i - k], i - k));
            dp[i] = ans;
        }
        return dp[n];
    }
    
    int integerBreak(int n) {
        // memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};