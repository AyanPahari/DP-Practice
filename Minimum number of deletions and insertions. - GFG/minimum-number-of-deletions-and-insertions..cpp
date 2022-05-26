// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string A, string B) { 
	    int m = A.length();
        int n = B.length();
        int dp[m+1][n+1];
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(A[i-1] == B[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int lcs = dp[m][n];
        return (m - lcs) + (n - lcs);
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends