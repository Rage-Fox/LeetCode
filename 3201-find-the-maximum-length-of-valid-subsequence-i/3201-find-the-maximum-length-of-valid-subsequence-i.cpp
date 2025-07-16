class Solution {
public:
    int maximumLength(vector<int> &hnums){
        int hn=hnums.size();
        int he=0,ho=0;
        for(int hi=0;hi<hn;hi++){
            if(hnums[hi]%2!=0){
                ho++;
            }
            else{
                he++;
            }
        }
        int hans=max(ho,he);
        int hcurr=1;
        int hfl=hnums[0]%2;
        for(int hi=1;hi<hn;hi++){
            if(hnums[hi]%2!=hfl){
                hcurr++;
                hfl=!hfl;
            }
        }
        return max(hans,hcurr);
    }
};