class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        // c1 for elements in the range [a, b]
        // c2 for elements > b
        long long res = 0, c1 = 0, c2 = 0;
        for (int v : nums) {
            if (v < a) {
                // When we encounter an element < a,
                // it must move past all previously seen elements in [a, b] and > b
                res += c1 + c2;
            } else if (v <= b) {
                // When we encounter an element in the range [a, b],
                // it only needs to move past the elements > b
                c1++;
                res += c2;
            } else {
                // Element is > b
                c2++;
            }
        }
        return res % 1000000007;
    }
};