class Solution {
public:
    vector<int>res;
    void solve(int i, int j, vector<vector<int>>& grid, int row, int col){
        if(i >= row){
            res.push_back(j);
            return;
        }
        if(grid[i][j] == 1){
            if(j == col - 1 || grid[i][j + 1] == -1){
                res.push_back(-1);
                return;
            }
        }
        if(grid[i][j] == -1){
            if(j == 0 || grid[i][j - 1] == 1){
                res.push_back(-1);
                return;
            }
        }
        solve(i + 1, j + grid[i][j], grid, row, col);
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=0;i<col;i++){
            solve(0, i, grid, row, col);
        }
        return res;
    }
};