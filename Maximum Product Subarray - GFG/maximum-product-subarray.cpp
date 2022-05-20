// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

    long long solve(vector<long long>& arr, vector<pair<long long, long long>>& dp){
        dp[0].first = arr[0], dp[0].second = arr[0];
        for(int i=1;i<arr.size();i++){
            dp[i].first = max(arr[i], max(arr[i] * dp[i - 1].first, arr[i] * dp[i - 1].second));
            dp[i].second = min(arr[i], min(arr[i] * dp[i - 1].first, arr[i] * dp[i - 1].second));
        }
        long long res = INT_MIN;
        for(int i=0;i<arr.size();i++) res = max(res, dp[i].first);
        
        return res;
    }

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    vector<pair<long long, long long>>dp(n);
	    vector<long long>a;
	    for(auto it:arr) a.push_back(it);
	    return solve(a, dp);
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends