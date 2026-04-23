class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n),post(n);
        int mx=nums[0],mn=nums[n-1];
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            pre[i]=mx;
        }
        for(int i=n-1;i>=0;i--){
            mn=min(mn,nums[i]);
            post[i]=mn;
        }
        for(int i=0;i<n;i++){
            if(pre[i]-post[i]<=k){
                return i;
            }
        }
        return -1;
    }
};