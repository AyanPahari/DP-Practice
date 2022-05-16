class Solution {
public:
    
    // bool checkpal(string pal, int low, int high){
    //     if(low>high) return true;
    //     if(pal[low] != pal[high]) return false;
    //     return checkpal(pal, low + 1, high - 1);
    // }
    
    bool isPalindrome(string s) {
        string pal;
        for(int i=0;i<s.length();i++){
            if(isupper(s[i])) s[i] = tolower(s[i]);
            if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57)) pal.push_back(s[i]);
        }
        int low = 0;
        int high = pal.size() - 1;
        // return checkpal(pal, low, high);
        
        while(low < high) if(pal[low++] != pal[high--]) return false;
        return true;
    }
};