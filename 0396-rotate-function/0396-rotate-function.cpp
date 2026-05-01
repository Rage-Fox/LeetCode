class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // F(1) = 1×nums[0]+2×nums[1]+…+0×nums[n−1] = F(0)+numSum−n×nums[n−1]
        int f=0,n=nums.size();
        int numSum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++){
            f+=i*nums[i];
        }
        int res=f;
        for(int i=n-1;i>0;i--){
            f+=numSum-n*nums[i];
            res=max(res,f);
        }
        return res;
    }
};