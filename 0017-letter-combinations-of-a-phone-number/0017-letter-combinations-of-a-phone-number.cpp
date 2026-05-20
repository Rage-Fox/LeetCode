class Solution {
public:
    // Same approach of backtracking to generate combinations-->
    // https://leetcode.com/problems/combinations/
    string mapping[10] = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(string res, vector<string>& ans, string digits, int i) {
        if (i >= digits.length()) {
            ans.push_back(res);
            return;
        }
        int index = digits[i] - '0';
        string val = mapping[index];
        for (int j = 0; j < val.length(); j++) {
            solve(res + val[j], ans, digits, i + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;
        string res = "";
        solve(res, ans, digits, 0);
        return ans;
    }
};