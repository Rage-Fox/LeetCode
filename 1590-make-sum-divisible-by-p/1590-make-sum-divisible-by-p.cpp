class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size(),s=0,pre=0,res=n;
        for(auto it:nums){
            s=((s%p)+(it%p))%p;
        }
        if(s==0){
            return 0;
        }
        unordered_map<int,int> mpp={{0,-1}};
        for(int i=0;i<n;i++){
            pre=((pre%p)+(nums[i]%p))%p;
            mpp[pre]=i;
            int rem=(pre-s+p)%p;
            if(mpp.count(rem)){
                res=min(res,i-mpp[rem]);
            }
        }
        return res<n?res:-1;
    }
};