class Solution {
public:
    int minOperations(string s1, string s2) {
        if (s1 == "1" && s2 == "0") {
            return -1;
        }
        int res = 0, n = s1.length();
        for (int i = 0; i < n; i++) {
            // no action is needed when character matches
            if (s1[i] == s2[i])
                continue;
            if (s1[i] == '0') {
                // We flip s1[i] to 1, costs 1 op
                res++;
            } else if (i < n - 1) {
                // adjacent characters
                res += s1[i + 1] == '1' ? 1 : 2;
                s1[i + 1] = '0';
            } else {
                // We need two operations by changing s[n−2], and flip both s[n−2] and s[n−1]
                res += 2;
            }
        }
        return res;
    }
};