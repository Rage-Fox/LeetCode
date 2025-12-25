class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        int selected=0;
        long long happinessScore=0;
        for(int score:happiness){
            if(selected==k){
                break;
            }
            happinessScore+=max(0,score-selected);
            selected++;
        }
        return happinessScore;
    }
};