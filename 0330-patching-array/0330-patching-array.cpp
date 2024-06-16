class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long patch=0;
        int count=0,index=0;
        while(patch<n){
            if(index<nums.size() && patch+1>=nums[index]){
                patch+=nums[index];
                index++;
            }
            else{
                // If the sum is not available then add the next number of the current sum
                patch+=(patch+1);
                count++;
            }
        }
        return count;
    }
};