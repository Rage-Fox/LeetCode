class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long total_pairs=(long long)n*(n-1)/2;
        unordered_map<int,int> diff_counts;
        long long good_pairs=0;
        for(int i=0;i<n;i++){
            int diff=nums[i]-i;
            good_pairs+=diff_counts[diff];// Calculating good pairs with present index
            // Counting present index diff later to count it with later indexes
            diff_counts[diff]++;
        }
        return total_pairs-good_pairs;
    }
};