class Solution {
public:
    vector<string> createGrid(int hm, int hn) {
        vector<string> hres(hm,string(hn,'#'));
        for(int hi=0;hi<hn;hi++){
            hres[0][hi]='.';
        }
        for(int hi=0;hi<hm;hi++){
            hres[hi][hn-1]='.';
        }
        return hres;
    }
};