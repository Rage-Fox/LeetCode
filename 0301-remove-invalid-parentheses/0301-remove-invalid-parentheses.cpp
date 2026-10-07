class Solution {
public:
    vector<string> res;
    int maxLen = 0;
    bool isValid(const string &s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') balance--;
            if (balance < 0) return false;
        }
        return balance == 0;
    }
    void backtrack(string s, int start) {
        if (isValid(s)) {
            if (s.size() >= maxLen) {
                if (s.size() > maxLen) {
                    res.clear();
                    maxLen = s.size();
                }
                if (find(res.begin(), res.end(), s) == res.end()) {
                    res.push_back(s);
                }
            }
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (i > start && s[i] == s[i - 1]) continue;
            if (s[i] == '(' || s[i] == ')') {
                string next = s.substr(0, i) + s.substr(i + 1);
                backtrack(next, i);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        res.clear();
        maxLen = 0;
        backtrack(s, 0);
        return res;
    }
};