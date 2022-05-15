class Solution {
public:
    
    int numSquares(int n) {
        vector<int>arr;
        for(int i=1;i*i<=n;i++) arr.push_back(i*i);
        // the problem no reduces to the unbounded knapsack.
        int size = arr.size();
        int t[size+1][n+1];
        
        for(int i=0;i<size+1;i++) t[i][0] = 0;
        for(int i=0;i<n+1;i++) t[0][i] = INT_MAX-1;
            
        for(int i=1;i<size+1;i++){
            for(int j=1;j<n+1;j++){
                if(arr[i-1] <= j) t[i][j] = min(1 + t[i][j-arr[i-1]], t[i-1][j]);
                else t[i][j] = t[i-1][j];
            }
        }
        return t[size][n];
    }
};