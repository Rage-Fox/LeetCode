class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result=prices;
        stack<int> stack;// To store indexes
        for(int i=0;i<prices.size();i++){
            // If current index's element is less than stack's top index element, then current index element will be the discount
            while(!stack.empty() and prices[stack.top()]>=prices[i]){
                result[stack.top()]-=prices[i];
                stack.pop();
            }
            stack.push(i);
        }
        return result;
    }
};