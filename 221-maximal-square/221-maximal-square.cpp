class Solution {
public:
    int dp[301][301];
    int solve(int i, int j, vector<vector<char>>& grid){
        if(i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1 + min(min(solve(i, j + 1, grid),solve(i + 1, j, grid)),solve(i + 1, j + 1, grid));
        return dp[i][j] = ans;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int side = 0;
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == '1') side = max(side, solve(i, j, matrix));
            }
        }
        return side * side;
    }
};