class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int totx=0,mask=(1<<maximumBit)-1;
        vector<int> res(nums.size());
        for(int num:nums){
            totx^=num;
        }
        for(int i=nums.size()-1;i>=0;i--){
            res[nums.size()-1-i]=totx^mask;
            totx^=nums[i];
        }
        return res;
    }
};