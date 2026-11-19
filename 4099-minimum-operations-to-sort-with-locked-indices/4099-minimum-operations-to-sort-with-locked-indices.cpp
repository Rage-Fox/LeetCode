class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size(), ops = 0, reqK = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    if (locked[j]) {
                        locked[j] = 0;
                        reqK++;
                    }
                    if (locked[j + 1]) {
                        locked[j + 1] = 0;
                        reqK++;
                    }
                    swap(nums[j], nums[j + 1]);
                    ops++;
                }
            }
        }
        if (reqK > k)
            return -1;
        return ops + reqK;
    }
};