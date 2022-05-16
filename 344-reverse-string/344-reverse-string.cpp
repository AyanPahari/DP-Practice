class Solution {
public:
    
    void solve(vector<char>& s, int low){
        // if(low > high) return;
        if(low >= s.size() - 1 - low) return;
        swap(s[low],s[s.size() - 1 - low]);
        solve(s, low + 1);
    }
    
    void reverseString(vector<char>& s) {
        int low = 0;
        // int high = s.size() - 1;
        // solve(s, low, high);
        solve(s,low);
    }
};