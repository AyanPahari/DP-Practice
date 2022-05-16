class Solution {
public:
    int dp[1001];
    int mod = 1e9 + 7;
    
    int solve(int n){
        // if(n <= 1) return 1;
        // if(dp[n]!=-1) return dp[n];
        // int ans = 0;
        // for(int i=1;i<=n;i++){
        //     if(i == 1 || i == 2) ans = (ans + solve(n-i)) % mod;
        //     else ans = (ans % mod + 2 * solve(n-i) % mod) % mod;
        // }
        // return dp[n] = ans;
        
        // Time Complexity - O(n^2)
        // Space Complexity - O(n)
        dp[0] = 1, dp[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(j == 1 || j == 2) dp[i] = (dp[i] + dp[i - j]) % mod;
                else dp[i] = (dp[i] % mod + 2 * dp[i - j] % mod) % mod;
            }
        }
        return dp[n];
    }
    
    int numTilings(int n) {
        // memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};