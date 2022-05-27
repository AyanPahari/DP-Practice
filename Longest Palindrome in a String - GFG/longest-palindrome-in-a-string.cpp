// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string A) {
        
        string B = A;
        reverse(B.begin(),B.end());
        int m = A.length();
        int n = B.length();
        int dp[m+1][n+1];
        
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
            }
        }
        int maxi = INT_MIN;
        string res;
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(A[i - 1] == B[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if(dp[i][j] > maxi){
                        
                        string temp = A.substr(i - dp[i][j], dp[i][j]);
                        string rev = temp;
                        reverse(rev.begin(),rev.end());
                        if(temp == rev){
                            maxi = dp[i][j];
                            res = temp;
                        }
                    }
                }
                else dp[i][j] = 0;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends