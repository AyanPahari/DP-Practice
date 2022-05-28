class Solution {
public:
    
    int dp[2501][2501];
    int solve(int index, int prev_index, vector<int>& arr){
        if(index == arr.size()) return 0;
        if(dp[index][prev_index+1] != -1) return dp[index][prev_index+1];
        
        int len = solve(index + 1, prev_index, arr);
        if(prev_index == -1 || arr[index] > arr[prev_index]) len = max(len, 1 + solve(index + 1, index, arr));
        
        return dp[index][prev_index+1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0, -1, nums);
    }
};