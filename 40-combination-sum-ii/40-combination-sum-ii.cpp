class Solution {
public:
    
    void solve(int ind, vector<int>candidates, int target, vector<vector<int>>& res, vector<int>output, int n){
        if(target == 0){
            res.push_back(output);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            output.push_back(candidates[i]);
            solve(i+1, candidates, target - candidates[i], res, output, n);
            output.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>output;
        sort(candidates.begin(),candidates.end());
        solve(0, candidates, target, res, output, candidates.size());
        return res;
    }
};