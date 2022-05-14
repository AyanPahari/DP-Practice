class Solution {
public:
    
    void isSubsetSum(vector<int>arr, int sum, int n, vector<int>& last_row){
        bool t[n+1][sum+1];
        for(int j=0;j<sum+1;j++) t[0][j] = false;
        for(int i=0;i<n+1;i++) t[i][0] = true;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1] <= j) t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else t[i][j] = t[i-1][j];
            }
        }
        for(int j=0;j<=sum/2;j++){
            if(t[n][j] == true) last_row.push_back(j);
        }
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        for(int i=0;i<n;i++) sum += stones[i];
        
        vector<int>last_row;
        isSubsetSum(stones, sum, n, last_row);
        
        int mini = INT_MAX;
        for(int i=0;i<last_row.size();i++) mini = min(mini, sum - 2 * last_row[i]);
        
        return mini;
    }
};