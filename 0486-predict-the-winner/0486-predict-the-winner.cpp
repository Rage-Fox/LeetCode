class Solution {
public:
    /*
    we have two choices either to choose the first or last so we will choose the
    element which gives us the best result ans the other one will choose a
    number which will be maximum of his choice. if we choose the first number i
    then opponent can choose either i+1 or jth number then he has two choices if
    i+1 we get i+2,j and if he chooses jth we get i+1,j-1 . after what he
    chooses he will try to give us as minimum result as possible. if we choose
    last number then the other player will get i,j-1 the he will choose either
    i+1 or j-1 then we get i+1,j-1 or i,j-2 and we will have minimum after these
    choices
    */
    int f(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];
        if (dp[i][j] != -1)
            return dp[i][j];
        int a = nums[i] + min(f(nums, i + 2, j, dp), f(nums, i + 1, j - 1, dp));
        int b = nums[j] + min(f(nums, i, j - 2, dp), f(nums, i + 1, j - 1, dp));
        dp[i][j] = max(a, b);
        return dp[i][j];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int sum = 0;
        for (auto i : nums) {
            sum += i;
        }
        int ans = f(nums, 0, n - 1, dp);
        int ans2 = sum - ans;
        return ans >= ans2;
    }
};