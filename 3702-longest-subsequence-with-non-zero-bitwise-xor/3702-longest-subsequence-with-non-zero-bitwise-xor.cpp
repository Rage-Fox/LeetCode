class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        /*
        Case 1: totalXor!=0
            In this case, the entire array nums itself is a non-empty subsequence whose bitwise XOR is non-zero. Therefore, the answer is n.
        Case 2: totalXor=0 and all elements in nums are 0
            In this case, the bitwise XOR of any non-empty subsequence is 0.
            Therefore, there is no non-empty subsequence whose bitwise XOR is non-zero, so the answer is 0.
        Case 3: totalXor=0 and there exists at least one element x!=0 in nums
            Since totalXor=0 and x!=0, there must be at least one other element in nums.
        */
        int n = nums.size(), totalXor = 0;
        bool allZero = true;
        for (int x : nums) {
            totalXor ^= x;
            if (x > 0) {
                allZero = false;
            }
        }
        if (totalXor > 0) {
            return n;
        }
        return allZero ? 0 : n - 1;
    }
};