class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.length(), a = -1, ab = -1, abc = -1;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a')
                a = i;
            else if (s[i] == 'b' && a != -1)
                ab = a;
            else if (s[i] == 'c' && ab != -1)
                abc = ab;
            // if no abc found, then i+1 substrings are valid
            ans += i - abc;
        }
        return ans;
    }
};