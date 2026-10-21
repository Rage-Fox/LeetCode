class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (ranges::is_sorted(s)) {
            return 0;
        }
        if (n == 2) {
            return -1;
        }
        char minChar = 'z';
        char maxChar = 'a';
        for (char ch : s) {
            minChar = min(minChar, ch);
            maxChar = max(maxChar, ch);
        }
        if (minChar == s[0] || maxChar == s[n - 1]) {
            return 1;
        }
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == minChar || s[i] == maxChar) {
                return 2;
            }
        }
        return 3;
    }
};