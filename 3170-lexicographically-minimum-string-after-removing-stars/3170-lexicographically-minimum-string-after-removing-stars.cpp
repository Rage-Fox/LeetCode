class Solution {
public:
    string clearStars(string hs) {
        string hres;
        unordered_map<char,vector<int>> hmpp;
        vector<int> hfreq(26,0),ht;
        for(int hi=0;hi<hs.size();hi++){
            if(hs[hi]=='*'){
                for(int hj=0;hj<26;hj++){
                    if(hfreq[hj]>0){
                        hfreq[hj]--;
                        hmpp[hj+'a'].pop_back();
                        break;
                    }
                }
            }
            else{
                hfreq[hs[hi]-'a']++;
                hmpp[hs[hi]].push_back(hi);
            }
        }
        for(auto hi:hmpp){
            for(auto hv:hi.second){
                ht.push_back(hv);
            }
        }
        sort(ht.begin(),ht.end());
        for(auto hi:ht){
            hres+=hs[hi];
        }
        return hres;
    }
};