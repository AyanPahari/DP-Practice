class Solution {
public:
    
    int dp[60];
    int solve(int n){
        // if(n <= 1) return 1;
        // if(dp[n]!=-1) return dp[n];
        dp[1] = 1;
        
        for(int i=2;i<=n;i++){
            for(int k=1;k<i;k++) dp[i] = max(dp[i], k * max(dp[i - k], i - k));
        }
        return dp[n];
    }
    
    int integerBreak(int n) {
        // memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};