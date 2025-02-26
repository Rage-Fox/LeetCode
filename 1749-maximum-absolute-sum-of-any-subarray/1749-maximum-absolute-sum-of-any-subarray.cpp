class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // Prefix Sum + Greedy => https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/solutions/6405609/maximum-absolute-sum-of-any-subarray
        int minPrefixSum=INT_MAX,maxPrefixSum=INT_MIN;
        int prefixSum=0,maxAbsSum=0;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            minPrefixSum=min(minPrefixSum,prefixSum);
            maxPrefixSum=max(maxPrefixSum,prefixSum);
            if(prefixSum>=0){
                // If the prefixSum is positive, we will get the difference
                // between prefixSum & minPrefixSum
                maxAbsSum=max(maxAbsSum,max(prefixSum,prefixSum-minPrefixSum));
            }
            else if(prefixSum<=0){
                // If the prefixSum is negative, we will get the absolute
                // difference between prefixSum & maxPrefixSum
                maxAbsSum=max(maxAbsSum,max(abs(prefixSum),abs(prefixSum-maxPrefixSum)));
            }
        }
        return maxAbsSum;
    }
};