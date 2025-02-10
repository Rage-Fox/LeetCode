class Solution {
public:
    string clearDigits(string hs){
        string hres="";
        for(auto hi:hs){
            if(!isdigit(hi)){
                hres+=hi;
            }
            else{
                hres.pop_back();
            }
        }
        return hres;
    }
};