class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int> cnt;
        int ans=0;
        for(auto &domino:dominoes){
            if(domino[0]>domino[1]){
                swap(domino[0],domino[1]);
            }
            ans+=cnt[domino]++;
        }
        return ans;
    }
};