class Solution {
public:
    
    void solve(int ind, vector<int>candidates, int target, vector<vector<int>>& res, vector<int>output, int n, int sum){
        if(sum>target) return;
        if(sum == target){
            res.push_back(output);
            return;
        }
        if(ind == n) return;
        
        output.push_back(candidates[ind]);
        sum += candidates[ind];
        
        solve(ind, candidates, target, res, output, n, sum);
        
        output.pop_back();
        sum -= candidates[ind];
        
        solve(ind+1, candidates, target, res, output, n, sum);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>output;
        solve(0, candidates, target, res, output, candidates.size(), 0);
        return res;
    }
};