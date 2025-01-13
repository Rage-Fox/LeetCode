class Solution {
public:
    int minimumLength(string hs){
        unordered_map<char,int> hmpp;
        for(auto hit:hs){
            hmpp[hit]++;
        }
        int hresans=0;
        for(auto hit:hmpp){
            if(hit.second>=3){
                if(hit.second&1){
                    hresans++;
                }
                else{
                    hresans++;
                    hresans++;
                }
            }
            else{
                hresans+=hit.second;
            }
        }
        return hresans;
    }
};