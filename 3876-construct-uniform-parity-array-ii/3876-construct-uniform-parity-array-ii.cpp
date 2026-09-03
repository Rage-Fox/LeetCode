class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        // Explanation: https://leetcode.com/problems/construct-uniform-parity-array-ii/solutions/8498445/100-beats-why-is-it-not-always-true-the-4slv9
        int smallestOdd = INT_MAX;
        for (int num : nums) {
            if (num % 2 == 1)
                smallestOdd = min(smallestOdd, num);
        }
        // Already all even
        if (smallestOdd == INT_MAX)
            return true;
        // Check whether every even number can become odd
        for (int num : nums) {
            if (num % 2 == 0 && num <= smallestOdd)
                return false;
        }
        return true;
    }
};