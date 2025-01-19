class Solution {
public:
    long long calculate(vector<int>& arr,vector<int>& brr){
        int n=arr.size();
        long long diff=0;
        for(int i=0;i<n;i++){
            diff+=abs(arr[i]-brr[i]);
        }
        return diff;
    }
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        // Calculating cost without rearranging
        long long ans=calculate(arr,brr);
        // Calculating cost after rearranging with considering fixed cost of "k" for splitting array into contiguous subarrays of size 1
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        ans=min(ans,calculate(arr,brr)+k);
        return ans;
    }
};