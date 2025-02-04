class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size(),currsum=nums[0],maxsum=nums[0],i=1;
        while(i<n){
            if(nums[i]>nums[i-1]){
                currsum+=nums[i];
            }
            else{
                maxsum=max(maxsum,currsum);
                currsum=nums[i];
            }
            i++;
        }
        maxsum=max(maxsum,currsum);
        return maxsum;
    }
};