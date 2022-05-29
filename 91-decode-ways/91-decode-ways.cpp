class Solution {
public:
    
    int dp[101];
    bool check(string s){
        int x = stoi(s);
        return (x >= 1 && x <= 26);
    }
    
    int solve(int index, string &s){
        if(index == s.length()) return 1;
        if(s[index] == '0') return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int ans = 0;
        ans += solve(index + 1, s);
        if(index + 2 <= s.length() && check(s.substr(index, 2))) ans += solve(index + 2, s);
        return dp[index] = ans;
    }
    
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }
};