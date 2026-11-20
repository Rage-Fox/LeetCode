class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size(), count = 0;
        unordered_map<int, int> freq1, freq2;
        for (int i = 0; i < n; i++) {
            freq1[nums[i]]++;
            freq2[target[i]]++;
        }
        if (freq1 != freq2) {
            return 0;
        }
        int maxI = n - 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                maxI = i;
                break;
            }
        }
        int minI = 0;
        for (int i = n - 1; i > 0; i--) {
            if (target[i] > target[i - 1]) {
                minI = i;
                break;
            }
        }
        count = max(0, maxI - minI + 1);
        return count;
    }
};