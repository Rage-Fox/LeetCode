class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int t=nums[nums.size()/2],sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=abs(nums[i]-t);
        }
        return sum;
    }
};