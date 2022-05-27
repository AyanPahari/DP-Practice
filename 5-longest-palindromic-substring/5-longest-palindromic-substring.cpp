class Solution {
public:
    string longestPalindrome(string A) {
        //1. first find the LCS(A, rev(A))
        //2. using the table start from any highest value and go (i-1,j-1) after adding that element
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
        // int x,y;
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(A[i - 1] == B[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if(dp[i][j] > maxi){
                        // maxi = dp[i][j];
                        // x = i;
                        // y = j;
                        
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
        // while(x > 0 && y > 0){
        //     if(A[x - 1] == B[y - 1]){
        //         res.push_back(A[x - 1]);
        //         x--;
        //         y--;
        //     }
        //     else break;
        // }
        return res;
    }
};