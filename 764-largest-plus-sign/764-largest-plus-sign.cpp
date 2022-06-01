class Solution {
public:
    
//     int dp[501][501];
//     int solve(int i, int j, vector<vector<int>> &grid, string dir){
//         if(i >= grid.size() || j >= grid.size() || i < 0 || j < 0 || grid[i][j] == 0) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int ans = 0;
//         if(dir == "left") ans = 1 + solve(i, j - 1, grid, dir);
//         if(dir == "right") ans = 1 + solve(i, j + 1, grid, dir);
//         if(dir == "up") ans = 1 + solve(i - 1, j, grid, dir);
//         if(dir == "down") ans = 1 + solve(i + 1, j, grid, dir);
        
//         return dp[i][j] = ans;
//     }
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>grid(n, vector<int>(n, 1));
        
        for(int i=0;i<mines.size();i++) grid[mines[i][0]][mines[i][1]] = 0;
        vector<vector<int>>left(n, vector<int>(n, 0));
        vector<vector<int>>right(n, vector<int>(n, 0));
        vector<vector<int>>up(n, vector<int>(n, 0));
        vector<vector<int>>down(n, vector<int>(n, 0));
        
        for(int i=0;i<n;i++){ // to populate the left vector
            int count = 0;
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) count += grid[i][j];
                else count = 0;
                left[i][j] = count;
            }
        }
        
        for(int i=0;i<n;i++){ // to populate the right vector
            int count = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j] == 1) count += grid[i][j];
                else count = 0;
                right[i][j] = count;
            }
        }
        
        for(int i=0;i<n;i++){ // to populate the up vector
            int count = 0;
            for(int j=0;j<n;j++){
                if(grid[j][i] == 1) count += grid[j][i];
                else count = 0;
                up[j][i] = count;
            }
        }
        
        for(int i=0;i<n;i++){ // to populate the down vector
            int count = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[j][i] == 1) count += grid[j][i];
                else count = 0;
                down[j][i] = count;
            }
        }
        
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
//                     memset(dp, -1, sizeof(dp));
//                     int left = solve(i, j - 1, grid, "left");
//                     int right = solve(i, j + 1, grid, "right");
//                     int up = solve(i-1, j, grid, "up");
//                     int down = solve(i + 1, j, grid, "down");
                    
//                     int ans = 1 + min(min(min(left, right), up), down);
//                     maxi = max(maxi, ans);

                    int ans = min(min(min(left[i][j], right[i][j]), up[i][j]), down[i][j]);
                    maxi = max(maxi, ans);
                }
            }
        }
        return maxi;
    }
};