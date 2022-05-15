class Solution {
public:
    
//     int solve(vector<int>arr, int sum, int n, vector<vector<int>>& t){
//         if(sum == 0) return 0;
//         if(n == 0) return INT_MAX - 1;
//         if(t[n][sum] != -1) return t[n][sum];
        
//         if(arr[n-1] <= sum) return t[n][sum] = min(1 + solve(arr, sum - arr[n-1], n, t), solve(arr, sum, n-1, t));
//         else return t[n][sum] = solve(arr, sum, n-1, t);
//     }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int t[n+1][amount+1];  

        for(int j=0; j <= amount; j++)
            t[0][j] = amount+1;
        for(int i=0; i <= n; i++)
            t[i][0] = 0;
        
        for(int i=1; i <= n; i++){
            for(int j=1; j <= amount; j++) {
                if(coins[i-1] <= j)
                    t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        
        return t[n][amount] > amount ? -1 : t[n][amount];
    }
};