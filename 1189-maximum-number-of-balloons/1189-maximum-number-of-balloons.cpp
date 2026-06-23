class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};
        for (char c : text) {
            freq[c - 'a']++;
        }
        // balloon: 1-b,1-a,2-l,2-o,1-n
        return min({freq['a' - 'a'], freq['b' - 'a'], freq['l' - 'a'] / 2,
                    freq['o' - 'a'] / 2, freq['n' - 'a']});
    }
};