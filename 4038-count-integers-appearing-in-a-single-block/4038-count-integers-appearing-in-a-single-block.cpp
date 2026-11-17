class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        mpp[nums[0]] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                mpp[nums[i]]++;
            }
        }
        int cnt = 0;
        for (auto it : mpp) {
            if (it.second == 1) {
                cnt++;
            }
        }
        return cnt;
    }
};