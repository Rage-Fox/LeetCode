class Solution {
public:
    vector<int> getSneakyNumbers(vector<int> &hnums){
        unordered_map<int,int> hmpp;
        for(auto hit:hnums){
            hmpp[hit]++;
        }
        vector<int> hresans;
        for(auto hit:hmpp){
            if(hit.second>=2){
                hresans.push_back(hit.first);
            }
        }
        return hresans;
    }
};