class Solution {
public:
    
    bool checkpow2(int x){
        return !(x & (x-1));
    }
    
    void solve(int n, vector<int>& dp){
        dp[0] = 0, dp[1] = 1;
        int last_pow = 1;
        for(int i=2;i<=n;i++){
            if(checkpow2(i)){
                last_pow = i;
                dp[i] = 1 + dp[i - i];
            }
            else dp[i] = 1 + dp[i - last_pow];
        }
    }
    
    vector<int> countBits(int n) {
        if(n == 0) return {0};
        vector<int>dp(n + 1,0);
        solve(n, dp);
        return dp;
    }
};