class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange){
        int res=numBottles;
        while(numBottles>=numExchange){
            int d=numBottles/numExchange;
            numBottles%=numExchange;
            res+=d;
            numBottles+=d;
        }
        return res;
    }
};