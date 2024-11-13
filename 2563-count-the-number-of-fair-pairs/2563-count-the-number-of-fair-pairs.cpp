class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
           auto a=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
           auto b=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
           ans+=(b-a);
        }
        return ans;
    }
};