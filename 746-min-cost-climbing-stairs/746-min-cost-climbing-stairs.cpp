class Solution {
public:
    
    int dp[1001];
    int solve(vector<int>& cost, int n){
        if(n == 0 || n == 1) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = min(cost[n-1] + solve(cost, n-1), cost[n-2] + solve(cost, n-2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return solve(cost, cost.size());
    }
};