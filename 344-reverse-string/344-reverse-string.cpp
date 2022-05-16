class Solution {
public:
    
    void solve(vector<char>& s, int low, int high){
        if(low > high) return;
        swap(s[low],s[high]);
        solve(s, low + 1, high - 1);
    }
    
    void reverseString(vector<char>& s) {
        int low = 0;
        int high = s.size() - 1;
        solve(s, low, high);
    }
};