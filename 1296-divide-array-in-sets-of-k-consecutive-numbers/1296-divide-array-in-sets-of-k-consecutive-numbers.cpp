class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0)
            return false;
        unordered_map<int, int> count;
        for (int num : nums)
            count[num]++;
        for (int num : nums) {
            int start = num;
            while (count[start - 1] > 0)
                start--;
            while (start <= num) {
                while (count[start] > 0) {
                    for (int i = start; i < start + k; i++) {
                        if (count[i] == 0)
                            return false;
                        count[i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};