class Solution {
public:
    // using backtracking
    vector<vector<int>> ans;
    void backtrack(vector<int>& cur, vector<int>& nums, vector<bool>& pick) {
        if (cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!pick[i]) {
                cur.push_back(nums[i]);
                pick[i] = true;
                backtrack(cur, nums, pick);
                cur.pop_back();
                pick[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur = {};
        vector<bool> pick(nums.size(), false);
        backtrack(cur, nums, pick);
        return ans;
    }
};