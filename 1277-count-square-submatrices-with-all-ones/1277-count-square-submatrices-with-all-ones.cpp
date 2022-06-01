class Solution {
public:
    
    int dp[301][301];
    int solve(int i, int j, vector<vector<int>>& matrix){
        if(i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        ans += 1 + min(min(solve(i, j + 1, matrix),solve(i + 1, j, matrix)),solve(i + 1, j + 1, matrix));
        return dp[i][j] = ans;
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 1){
                    res += solve(i, j, matrix);
                }
            }
        }
        return res;
    }
};