class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        // rob1 - best until i-2, rob2 - best until i-1
        for (int num : nums) {
            int temp = max(num + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2; // need n-1 at last
    }
};