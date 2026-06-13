class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res="";
        for(auto w:words){
            int s=0;
            for(auto i:w){
                s+=weights[i-'a'];
            }
            res+='z'-(s%26);
        }
        return res;
    }
};