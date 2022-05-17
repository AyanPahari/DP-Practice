// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	    void solve(int ind, vector<string>& res, int n, string output, string s){
	        if(ind >= n){
	            if(output.size() > 0) res.push_back(output);
	            return;
	        }
	        output.push_back(s[ind]);
	        solve(ind+1, res, n, output, s);
	        output.pop_back();
	        solve(ind+1, res, n, output, s);
	    }
	
		vector<string> AllPossibleStrings(string s){
		    vector<string>res;
		    string output;
		    solve(0, res, s.length(), output, s);
		    sort(res.begin(),res.end());
		    return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends