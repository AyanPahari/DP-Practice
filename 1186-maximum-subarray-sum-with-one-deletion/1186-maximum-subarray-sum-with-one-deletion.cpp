class Solution {
public:
    
    int solve(vector<int>& arr, int n, vector<int>& f, vector<int>& b){
        // let's first do the forward pass
        f[0] = arr[0];
        int maxi = arr[0];
        for(int i=1;i<n;i++){
            f[i] = max(arr[i], arr[i] + f[i - 1]);
            maxi = max(maxi, f[i]);
        }
        // let's first do the forward pass
        b[n - 1] = arr[n - 1];
        for(int i=n-2;i>=0;i--){
            b[i] = max(arr[i], arr[i] + b[i + 1]);
            maxi = max(maxi, b[i]);
        }
        // now we will exclude every single element(1...n-1) one by one and check for the maximum value
        for(int i=1;i<n;i++){
            if(i + 1 < n) maxi = max(maxi, f[i - 1] + b[i + 1]);
        }
        return maxi;
    }
    
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int>f(n); // forward dp array
        vector<int>b(n); // backward dp array
        return solve(arr, n, f, b);
    }
};