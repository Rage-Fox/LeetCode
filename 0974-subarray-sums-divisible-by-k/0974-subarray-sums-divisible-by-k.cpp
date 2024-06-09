class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int res=0,sum=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int r=sum%k;
            if(r<0)
                r=r+k;
            if(mpp.find(r)==mpp.end()){
                mpp[r]=1;
            }
            else{
                res+=mpp[r];
                mpp[r]++;
            }
        }
        return res;
    }
};