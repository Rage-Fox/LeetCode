class Solution {
public:
    int countMagicalPairs(string s) {
        int count = 0, n = s.length();
        for (int j = 0; j < n - 1; j++) {
            int lf[27] = {0}, rf[27] = {0};
            unordered_set<char> hs;
            for (int i = j; i >= 0; i--) {
                hs.insert(s[i]);
                lf[hs.size()]++;
            }
            hs.clear();
            for (int k = j + 1; k < n; k++) {
                hs.insert(s[k]);
                rf[hs.size()]++;
            }
            for (int d = 0; d < 27; d++) {
                count += lf[d] * rf[d];
            }
        }
        return count;
    }
};