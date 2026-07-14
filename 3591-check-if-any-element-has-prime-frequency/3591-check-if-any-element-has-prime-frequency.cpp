class Solution {
public:
    bool isprime(int n) {
        if (n < 2){
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int num : nums) {
            mpp[num]++;
        }
        for (auto it : mpp) {
            if (isprime(it.second)) {
                return true;
            }
        }
        return false;
    }
};