class Solution {
public:

    int solve(int startX, int startY, int count, vector<vector<int>>& grid){
        
        if(startX < 0 || startX >= grid.size() || startY < 0 || startY >= grid[0].size() || grid[startX][startY] == -1) return 0;
        if(grid[startX][startY] == 2){
            if(count == -1) return 1;
            else return 0;
        }
        grid[startX][startY] = -1;
        int ans = solve(startX - 1, startY, count - 1, grid) + 
                  solve(startX, startY + 1, count - 1, grid) + 
                  solve(startX + 1, startY, count - 1, grid) + 
                  solve(startX, startY - 1, count - 1, grid);
        grid[startX][startY] = 0;
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int startX, startY;
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    startX = i;
                    startY = j;
                }
                if(grid[i][j] == 0) count++;
            }
        }
        return solve(startX, startY, count, grid);
    }
};