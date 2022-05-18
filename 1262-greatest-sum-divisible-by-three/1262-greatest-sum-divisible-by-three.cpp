class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>t1(3,0);
        t1[nums[0] % 3] = nums[0];
        vector<int>t2;
        t2 = t1;
        for(int i=1;i<nums.size();i++){
            t2 = t1;
            t2[(nums[i] + t1[0]) % 3] = max(t2[(nums[i] + t1[0]) % 3],nums[i] + t1[0]);
            t2[(nums[i] + t1[1]) % 3] = max(t2[(nums[i] + t1[1]) % 3],nums[i] + t1[1]);
            t2[(nums[i] + t1[2]) % 3] = max(t2[(nums[i] + t1[2]) % 3],nums[i] + t1[2]);
            t1 = t2;
        }
        return t2[0];
    }
};