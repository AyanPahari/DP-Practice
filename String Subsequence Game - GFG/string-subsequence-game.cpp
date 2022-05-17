// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void solve(int ind, vector<string>& res, string S, int n, string output){
        if(ind >= n){
            res.push_back(output);
            return;
        }
        output.push_back(S[ind]);
        solve(ind+1, res, S, n, output);
        output.pop_back();
        solve(ind+1, res, S, n, output);
    }
  
    set<string> allPossibleSubsequences(string S) {
        vector<string>res;
        vector<string>final;
        string output;
        solve(0, res, S, S.length(), output);
        for(int i=0;i<res.size();i++){
            if((res[i][0] == 'a' || res[i][0] == 'e' || res[i][0] == 'i' || res[i][0] == 'o' || res[i][0] == 'u') && 
                (res[i][res[i].length() - 1] != 'a' && res[i][res[i].length() - 1] != 'e' && res[i][res[i].length() - 1] != 'i' && res[i][res[i].length() - 1] != 'o' && res[i][res[i].length() - 1] != 'u')){
                    final.push_back(res[i]);
            }
        }
        sort(final.begin(),final.end());
        set<string>ans;
        for(auto x:final) ans.insert(x);
        return ans;    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
  // } Driver Code Ends