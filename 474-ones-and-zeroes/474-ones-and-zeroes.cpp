class Solution {
public:
    
    vector<vector<int>> get_count(vector<string>& str){
        vector<vector<int>>res;
        for(int i=0;i<str.size();i++){
            int zeros = 0, ones = 0;
            for(int j=0;j<str[i].size();j++){
                if(str[i][j] == '0') zeros++;
                if(str[i][j] == '1') ones++;
            }
            res.push_back({zeros,ones});
        }
        return res;
    }
    
    int solve(vector<string>& str, int m, int n, int index, vector<vector<vector<int>>> &dp, vector<vector<int>> &helper){
        if((m <= 0 && n <= 0) || index < 0) return 0;
        if(dp[m][n][index] != -1) return dp[m][n][index];
        vector<int>count = helper[index];
        int ans = 0;
        if(count[0] <= m && count[1] <= n){
            ans = max(solve(str, m, n, index - 1, dp, helper), 1 + solve(str, m - count[0], n - count[1], index - 1, dp, helper));
        }
        else{
            ans = solve(str, m, n, index - 1, dp, helper);
        }
        return dp[m][n][index] = ans;
    }
    
    int findMaxForm(vector<string>& str, int m, int n) {
        vector<vector<vector<int>>>dp(m + 1, vector<vector<int>>(n + 1, vector<int>(str.size(), -1)));
        vector<vector<int>>helper = get_count(str);
        return solve(str, m, n, str.size() - 1, dp, helper);
    }
};