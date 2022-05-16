class Solution {
public:
    int dp[1001];
    int mod = 1e9 + 7;
    
    int solve(int n){
        if(n <= 1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(i == 1 || i == 2) ans = (ans + solve(n-i)) % mod;
            else ans = (ans % mod + 2 * solve(n-i) % mod) % mod;
        }
        return dp[n] = ans;
    }
    
    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};