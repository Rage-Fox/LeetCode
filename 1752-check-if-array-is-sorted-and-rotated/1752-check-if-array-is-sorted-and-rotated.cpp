class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size()==1){
            return true;
        }
        int i=0;
        while(i<nums.size()-1 and nums[i+1]>=nums[i]){
            i++;
        }
        if(i==nums.size()-1){
            return true;
        }
        i++;
        while(i<nums.size()-1 and nums[i+1]>=nums[i] and nums[i]<=nums[0]){
            i++;
        }
        if(i==nums.size()-1 and nums[i]<=nums[0]){
            return true;
        }
        return false;
    }
};