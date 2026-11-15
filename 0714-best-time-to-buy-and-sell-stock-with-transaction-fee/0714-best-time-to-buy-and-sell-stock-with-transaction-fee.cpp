class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2, 0), next(2, 0);
        for(int idx = n - 1; idx >= 0; idx--) {
            for(int canBuy = 1; canBuy >= 0; canBuy--) {
                int buy = -1e9, sell = -1e9;
                if(canBuy) {
                    buy = -prices[idx] + next[!canBuy];
                } else {
                    sell = prices[idx] - fee + next[!canBuy];
                }
                int move_on = next[canBuy];
                curr[canBuy] = max({buy, sell, move_on});                
            }
            next = curr;
        }
        return next[1];
    }
};