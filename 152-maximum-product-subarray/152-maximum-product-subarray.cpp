class Solution {
public:
    
    int solve(vector<int>& nums, vector<pair<int,int>>& dp){
        dp[0].first = nums[0];
        dp[0].second = nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i].first = max(nums[i], max(dp[i - 1].first * nums[i], dp[i - 1].second * nums[i]));
            dp[i].second = min(nums[i], min(dp[i - 1].first * nums[i], dp[i - 1].second * nums[i]));
        }
        
        // dp[i].first contains the max positive element and dp[i].second contains the max negative element
        
        int res = INT_MIN;
        for(int i=0;i<nums.size();i++) res = max(res, dp[i].first);
        return res;
    }
    
    int maxProduct(vector<int>& nums) {
        vector<pair<int,int>>dp(nums.size());
        return solve(nums, dp);
    }
};