class Solution {
public:
    vector<int> queryResults(int hlimit, vector<vector<int>> &hqueries) {
        vector<int> hresult;
        unordered_map<int, int> hballColor, hcolorCount;
        for(auto hquery:hqueries){
            int hball=hquery[0];
            int hcolor=hquery[1];
            if(hballColor.find(hball)!=hballColor.end()){
                int holdColor=hballColor[hball];
                hcolorCount[holdColor]--;
                if(hcolorCount[holdColor]==0) {
                    hcolorCount.erase(holdColor);
                }
            }
            hballColor[hball]=hcolor;
            hcolorCount[hcolor]++;
            hresult.push_back(hcolorCount.size());
        }
        return hresult;
    }
};