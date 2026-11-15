class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size())
            return 0;
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int profit1 = INT_MIN, profit2 = INT_MIN;
        // because you already have p1 bucks in your hand. Now, if you sell the
        // second stock at price y your net profit p2 will be p2 = y - (x-p1)
        for (int i = 0; i < prices.size(); i++) {
            buy1 = min(buy1, prices[i]);
            profit1 = max(profit1, prices[i] - buy1);
            buy2 = min(buy2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - buy2);
        }
        return profit2;
    }
};