class Solution {
public:
    int helper(vector<int> &nums,int index,int currValue){
        if(index==nums.size())
            return currValue;
        return helper(nums,index+1,currValue^nums[index])+helper(nums,index+1,currValue);
    }
    int subsetXORSum(vector<int>& nums) {
        return helper(nums,0,0);
    }
};