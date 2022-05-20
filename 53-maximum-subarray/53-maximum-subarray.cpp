class Solution {
public:

    int solve(vector<int>& nums, vector<int>& dp){
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++) dp[i] = max(nums[i] + dp[i - 1], nums[i]);
        return *max_element(dp.begin(),dp.end());
    }
    
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        return solve(nums,dp);
    }
};