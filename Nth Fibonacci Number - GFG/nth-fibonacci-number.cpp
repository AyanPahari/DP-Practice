// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    int mod = 1e9 + 7;
    long long int nthFibonacci(long long int n){
        long long a = 0;
        long long b = 1;
        long long c;
        for(int i=2;i<=n;i++){
            c = (a % mod + b % mod) % mod;
            a = b;
            b = c;
        }
        return c;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends