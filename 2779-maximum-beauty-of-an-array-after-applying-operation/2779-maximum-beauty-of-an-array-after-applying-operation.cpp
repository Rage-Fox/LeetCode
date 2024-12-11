class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=0,sum=0,ans=0;
        while(j<n){
            // (nums[i]+k)<(nums[j]-k)
            while(i<n and nums[i]+(2*k)<nums[j]){
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};