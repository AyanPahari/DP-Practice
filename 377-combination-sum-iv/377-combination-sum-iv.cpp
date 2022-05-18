class Solution {
public:
    int dp[1001];
    
    int solve(vector<int>arr, int sum){
        if(sum == 0) return 1;
        if(dp[sum]!=-1) return dp[sum];
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] <= sum) ans += solve(arr, sum - arr[i]);
        }
        return dp[sum] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums, target);
    }
};