class Solution {
public:
    vector<vector<int>> res;
    // each of the res[i] may have duplicates inside them but res array doesn't allow duplicates
    // meaning only [1,2,2] is allowed once in res but not more than once
    void backtrack(int i, vector<int> subset, vector<int>& nums) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }
        // accept duplicates for res[i]
        subset.push_back(nums[i]);
        backtrack(i + 1, subset, nums);
        subset.pop_back();
        // skip all the duplicates which came in res[i]
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        backtrack(i + 1, subset, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, {}, nums);
        return res;
    }
};