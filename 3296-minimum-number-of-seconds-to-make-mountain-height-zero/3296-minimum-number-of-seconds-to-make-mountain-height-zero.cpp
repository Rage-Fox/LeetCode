typedef long long ll;
class Solution {
public:
    bool solvable(int hmh,const vector<int> &hwt,ll htl){
        ll hc=0;
        for(int hi:hwt){
            ll hl=1,hr=hmh;
            while(hl<=hr){
                ll hm=hl+(hr-hl)/2;
                ll hrt=(hm*(hm+1)/2)*hi;
                if(hrt<=htl){
                    hl=hm+1;
                }
                else{
                    hr=hm-1;
                }
            }
            hc+=hr;
            if(hc>=hmh){
                return true;
            }
        }
        return hc>=hmh;
    }
    ll minNumberOfSeconds(int hmh,vector<int> &hwt){
        ll hl=0,hr=1e18,hresans=1e18;
        while(hl<=hr){
            ll hm=hl+(hr-hl)/2;
            if(solvable(hmh,hwt,hm)==true){
                hresans=hm;
                hr=hm-1;
            }
            else{
                hl=hm+1;
            }
        }
        return hresans;
    }
};