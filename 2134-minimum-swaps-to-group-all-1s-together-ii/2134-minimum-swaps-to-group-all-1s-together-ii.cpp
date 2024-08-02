class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int tot=accumulate(nums.begin(),nums.end(),0),s=0,i=0,ans=INT_MAX;
        // Doubling nums for circular array
        nums.insert(nums.end(),nums.begin(),nums.end());
        for(int j=0;j<nums.size();j++){
            s+=nums[j];
            if(j-i+1==tot){
                // Most possible 1's group
                ans=min(ans,tot-s);
                s-=nums[i++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};