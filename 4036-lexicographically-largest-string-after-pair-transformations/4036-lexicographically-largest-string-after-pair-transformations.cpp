class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        // Explanation: https://leetcode.com/problems/lexicographically-largest-string-after-pair-transformations/solutions/8489431/100-beats-simple-approach-with-visualiza-18hn
        vector<long long> convert(26, 0);
        long long base = 1;
        for(int i = 0; i < 26; i++){
            convert[i] = base;
            base *= 2;
        }
        vector<string> res;
        for(int n : nums){
            string cur = "";
            while(n > 0){
                int i = 25;
                while(convert[i] > n){
                    i--;
                }
                cur += (char)('a' + i);
                n -= convert[i];
            }
            res.push_back(cur);
        }
        return res;
    }
};