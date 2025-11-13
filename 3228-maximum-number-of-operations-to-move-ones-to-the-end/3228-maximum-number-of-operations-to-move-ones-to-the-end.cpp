class Solution {
public:
    int maxOperations(string hs){
        int hresans=0,hp=0;
        bool hflag=false;
        vector<int> hbits;
        for(auto hit:hs){
            if(hit=='1'){
                hbits.push_back(1);
                hflag=true;
            }
            else if(hit=='0' and hflag==true){
                hbits.push_back(0);
                hflag=false;
            }
        }
        for(auto hit:hbits){
            if(hit==1){
                hp++;
            }
            else{
                hresans+=hp;
            }
        }
        return hresans;
    }
};