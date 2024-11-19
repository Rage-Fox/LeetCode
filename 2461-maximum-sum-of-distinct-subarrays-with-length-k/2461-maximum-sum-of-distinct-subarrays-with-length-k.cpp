class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n=nums.size(),winsum=0,maxx=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            winsum+=nums[i];
            if(i>=k){
                int left=nums[i-k];
                mpp[left]--;
                winsum-=left;
                if(mpp[left]==0){
                    mpp.erase(left);
                }
            }
            if(i>=k-1 and mpp.size()==k){
                maxx=max(maxx,winsum);
            }
        }
        return maxx;
    }
};