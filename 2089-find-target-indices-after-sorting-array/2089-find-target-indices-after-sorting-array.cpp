class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count1 = 0, count2 = 0;
        for (const int num : nums) {
            if (num < target) {
                count1++;
            } else if (num == target) {
                count2++;
            }
        }
        vector<int> res;
        for (int i = count1; i < count1 + count2; i++) {
            res.push_back(i);
        }
        return res;
    }
};