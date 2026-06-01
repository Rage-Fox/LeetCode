class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int tprice=0;
        for(int i=0;i<cost.size();i+=3){
            tprice+=cost[i];
            if(i<cost.size()-1){
                tprice+=cost[i+1];
            }
        }
        return tprice;
    }
};