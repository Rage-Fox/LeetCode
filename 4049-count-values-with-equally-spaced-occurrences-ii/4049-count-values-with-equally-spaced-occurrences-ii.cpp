class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size(), res = 0;
        unordered_map<int, vector<int>> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }
        for (auto it : mpp) {
            if (it.second.size() >= 3) {
                bool flag = true;
                n = it.second.size();
                int dist = abs(it.second[1] - it.second[0]);
                for (int i = 1; i < n; i++) {
                    if (abs(it.second[i] - it.second[i - 1]) != dist) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res++;
                }
            }
        }
        return res;
    }
};