class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sumsubarray;
        int mod=1e9+7,ans=0;
        for(int i=0;i<n;i++){
            int k=0;
            for(int j=i;j<n;j++){
                k+=nums[j];
                sumsubarray.push_back(k);
            }
        }
        sort(sumsubarray.begin(),sumsubarray.end());
        for(int i=left-1;i<=right-1;i++){
            ans+=sumsubarray[i];
            ans=ans%mod;
        }
        return ans;
    }
};