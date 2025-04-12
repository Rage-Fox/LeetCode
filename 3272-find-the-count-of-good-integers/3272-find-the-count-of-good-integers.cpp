class Solution {
public:
    long long factorial(int num) {
        long long result = 1;
        for (int i = 2; i <= num; ++i) {
            result *= i;
        }
        return result;
    }
    long long countGoodIntegers(int n, int k) {
        int n2 = (n + 1) / 2;
        long long res = 0;
        unordered_set<string> seen;
        // Iterate through all possible half-length numbers
        /*pow(10, n2 - 1): This function calculates 10^n2−1. It gives the smallest number with n2 digits. If n2 = 3, then pow(10, 3 - 1) is 10^2, which is 100. So, it starts at 100 (the smallest 3-digit number).*/
        for (int v = pow(10, n2 - 1); v < pow(10, n2); ++v) {
            string v_str = to_string(v);
            string vv = v_str + string(v_str.rbegin() + (n % 2), v_str.rend());
            // Key to identify unique permutations
            string key = vv;
            sort(key.begin(), key.end());
            // Check if the number is divisible by k and not seen before
            if (stoll(vv) % k == 0 && seen.find(key) == seen.end()) {
                seen.insert(key);
                // Count frequency of each digit
                map<char, int> count;
                for (char c : vv) {
                    count[c]++;
                }
                // Calculate number of good integers based on permutations
                long long x = (n - count['0']) * factorial(n - 1);
                for (auto& p : count) {
                    x /= factorial(p.second);
                }
                res += x;
            }
        }
        return res;
    }
};