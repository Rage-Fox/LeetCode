class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long cost = 0, resources = k;
        int MOD = 1e9 + 7;
        for (int currResource : nums) {
            if (resources < currResource) {
                long long x = (currResource + k - 1 - resources) / k;
                cost += x;
                resources += x * k;
            }
            resources -= currResource;
        }
        cost %= MOD;
        return (cost * (cost + 1) / 2) % MOD;
    }
};