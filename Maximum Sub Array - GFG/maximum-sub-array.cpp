// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int arr[], int n) {
	    long long  curr_sum = 0;
	    long long  ans = INT_MIN;
	    int curr_strt = 0; 
	    int curr_end = -1; 
	    int final_strt = 0; 
	    int final_end = 0;
	    int curr_len = 0;
	    int final_len = 0;
	    int count = 0;
	    
	    for(int i=0;i<n;i++){
	        if(arr[i] < 0){
	           curr_strt = i+1;
	           curr_end = i;
	           curr_sum = 0;
	           count++;
	        }
	        
	        if(arr[i] >= 0){
	            curr_sum += arr[i];
	            curr_end++;
	        }
	        
	        curr_len = curr_end - curr_strt + 1;
	        
	        if(curr_sum > ans){
	            ans = curr_sum;
	            final_strt = curr_strt;
	            final_end = curr_end;
	        }
	        
	        if(curr_sum == ans && curr_len > final_len){
	            ans = curr_sum;
	            final_strt = curr_strt;
	            final_end = curr_end;
	            final_len = curr_len;
	        }
	    }
	    if(count == n) return {-1};
	    vector<int>res;
	    for(int i=final_strt;i<=final_end;i++) res.push_back(arr[i]);
	    
	    return res;
	}
};

// { Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends