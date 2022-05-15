class Solution {
public:
    int t[301][5001];
    
    int solve(vector<int>arr, int sum, int n){
        if(sum == 0) return 1;
        if(n == 0) return 0;
        if(t[n][sum]!=-1) return t[n][sum];
        
        if(arr[n-1] <= sum) return t[n][sum] = solve(arr, sum - arr[n-1], n) + solve(arr, sum, n-1);
        else return t[n][sum] = solve(arr, sum, n-1);
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(t,-1,sizeof(t));
        return solve(coins, amount, n);
    }
};