class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int l=start,r=start,n=nums.size();
        while(l>=0 or r<n){
            if(l>=0){
                if(nums[l]==target){
                    return start-l;
                }
                l--;
            }
            if(r<n){
                if(nums[r]==target){
                    return r-start;
                }
                r++;
            }
        }
        return INT_MAX;
    }
};