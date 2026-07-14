class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> sumByRange(10, 0);
        for (int num : nums) {
            int original = num;
            int maxDigit = 0;
            int minDigit = 9;
            while (num) {
                maxDigit = max(maxDigit, num % 10);
                minDigit = min(minDigit, num % 10);
                num /= 10;
            }
            sumByRange[maxDigit - minDigit] += original;
        }
        for (int range = 9; range >= 0; range--) {
            if (sumByRange[range] != 0) {
                return sumByRange[range];
            }
        }
        return 0;
    }
};