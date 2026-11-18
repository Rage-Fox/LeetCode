class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto it : mp) {
            if (it.second.size() == 3 && (abs(it.second[0] - it.second[1]) ==
                                          abs(it.second[2] - it.second[1]))) {
                res++;
            }
        }
        return res;
    }
};