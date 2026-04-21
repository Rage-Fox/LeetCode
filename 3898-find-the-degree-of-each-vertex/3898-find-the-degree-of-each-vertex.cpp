class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int> res;
        for(auto &it:matrix){
            res.push_back(accumulate(it.begin(),it.end(),0));
        }
        return res;
    }
};