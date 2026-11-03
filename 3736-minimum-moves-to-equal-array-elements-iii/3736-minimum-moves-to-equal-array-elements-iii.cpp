class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxx = nums[0];
        for (int x : nums) {
            maxx = max(maxx, x);
        }
        int ans = 0;
        for (int x : nums) {
            ans += maxx - x;
        }
        return ans;
    }
};