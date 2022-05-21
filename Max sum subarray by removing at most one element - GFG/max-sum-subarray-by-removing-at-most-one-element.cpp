// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    
    int solve(int arr[], vector<int>& f, vector<int>& b, int n){
        f[0] = arr[0];
        int maxi = arr[0];
        for(int i=1;i<n;i++){
            f[i] = max(arr[i], arr[i] + f[i - 1]);
            maxi = max(maxi, f[i]);
        }
        b[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            b[i] = max(arr[i], arr[i] + b[i + 1]);
            maxi = max(maxi, b[i]);
        }
        
        for(int i=1;i<n;i++){
            if(i + 1 < n) maxi = max(maxi, f[i - 1] + b[i + 1]);
        }
        return maxi;
    }
    
    int maxSumSubarray(int arr[], int n)
    {
        vector<int>f(n);
        vector<int>b(n);
        return solve(arr, f, b, n);
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	
	//taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking total elements
		int n;
		cin>>n;
		int a[n];
		
		//inserting elements in the array
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		
		//calling method maxSumSubarray()
		Solution obj;
		cout<<obj.maxSumSubarray(a,n)<<endl;
	}
}

  // } Driver Code Ends