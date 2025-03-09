class Solution {
public:
    int numberOfAlternatingGroups(vector<int> &hcolors,int hk){
        int hn=hcolors.size();
        int hcount=0;
        vector<int> hdupcolors=hcolors;
        for(int i=0;i<hk-1;i++){
            hdupcolors.push_back(hcolors[i]);
        }
        int hansres=0,hc=1;
        for(int hi=1;hi<hn+hk-1;hi++){
            if(hdupcolors[hi]!=hdupcolors[hi-1]){
                hc++;
            }
            else{
                hc=1;
            }
            if(hc>=hk){
                hansres++;
            }
        }
        return hansres;
    }
};