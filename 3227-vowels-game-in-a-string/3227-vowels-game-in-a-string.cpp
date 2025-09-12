class Solution {
public:
    bool doesAliceWin(string hs) {
        int hcount=0,hconso=0,hind=0;
        for(auto hi:hs){
            if(hi=='a' or hi=='e' or hi=='i' or hi=='o' or hi=='u'){
                hcount++;
                hind=hi;
            }
            else{
                hconso++;
            }
        }
        if(hcount==0){
            return false;
        }
        else{
            return true;
        }
    }
};