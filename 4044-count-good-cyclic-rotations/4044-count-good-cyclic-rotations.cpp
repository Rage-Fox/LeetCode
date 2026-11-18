class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long total = 0, firstHalf = 0;
        for (int x : nums) {
            total += x;
        }
        for (int i = 0; i < n / 2; i++) {
            firstHalf += nums[i];
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            // FirstHalf > SecondHalf condition
            if (2 * firstHalf > total) {
                count++;
            }
            firstHalf -= nums[i];
            firstHalf += nums[(i + n / 2) % n];
        }
        return count;
    }
};