class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        // Counting Sort
        // https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/solutions/8362244/on-without-sorting-beats-9958-with-dry-r-mlgb
        int n = arr.size();
        vector<int> cnt(n + 1, 0);
        for (int x : arr) {
            // Maximum can be upto "n" as adjacent diff is <=1
            cnt[min(x, n)]++;
        }
        int val = 0;
        for (int i = 1; i <= n; i++) {
            // first ele must be 1, so diff <=1 means we can replace (decrease) with continuous numbers
            val = min(i, val + cnt[i]);
        }
        return val;
    }
};