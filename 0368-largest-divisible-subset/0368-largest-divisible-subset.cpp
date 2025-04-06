class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // For each element nums[i], we iterate through all elements before it (nums[j], where j < i) and check if nums[i] is divisible by nums[j].
        // If it is divisible and adding nums[i] to the subset results in a larger subset, we update the dp[i] value.
        int n=nums.size(),maxi=1,num=-1;
        vector<int> v;
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int> prev(n,-1);
        int maxIdx=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i] = j;
                    if(dp[i]>dp[maxIdx]){
                        maxIdx=i;
                    }
                }
            }
        }
        // Once we have the maximum subset length, we iterate through the dp array from the end to reconstruct the largest divisible subset.
        // We start from the element that corresponds to the maximum subset length and backtrack by adding elements to the result vector (v) while ensuring that each element divides the next element in the subset.
        while(maxIdx>=0){
            v.push_back(nums[maxIdx]);
            maxIdx=prev[maxIdx];
        }
        reverse(v.begin(),v.end());
        return v;
    }
};