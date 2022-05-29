// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	
	int dp[10001];
	int mod = 1e9 + 7;
	bool check(string s){
	    int x = stoi(s);
	    return (x >= 1 && x <= 26);
	}
	
	int solve(int index, string &str){
	    if(index == str.length()) return 1;
	    if(str[index] == '0') return 0;
	    if(dp[index] != -1) return dp[index];
	    
	    int ans = 0;
	    ans = ((ans % mod) + (solve(index + 1, str) % mod)) % mod;
	    if(index + 2 <= str.length() && check(str.substr(index, 2)))
	        ans = ((ans % mod) + (solve(index + 2, str) % mod)) % mod;
	    
	    return dp[index] = ans;
	}
	
	int CountWays(string str){
	    memset(dp, -1, sizeof(dp));
	    return solve(0, str);
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends