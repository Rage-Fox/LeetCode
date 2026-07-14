class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int s1 = s.size(), t1 = t.size(), i = 0, j = 0;
        // we change the chat at most once
        bool changeOnce = true;
        for (int i = 0; i < t1; i++) {
            if (s[j] == t[i]) {
                j++;
            } else if (changeOnce) {
                changeOnce = false;
                j++;
            }
            if (j == s1) {
                return true;
            }
        }
        j = s1 - 1;
        // we do this same from last
        changeOnce = true;
        for (int i = t1 - 1; i >= 0; i--) {
            if (s[j] == t[i]) {
                j--;
            } else if (changeOnce) {
                changeOnce = false;
                j--;
            }
            if (j == -1) {
                return true;
            }
        }
        return false;
    }
};