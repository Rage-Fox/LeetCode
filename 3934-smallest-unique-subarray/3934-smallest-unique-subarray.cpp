class Solution {
public:
    typedef unsigned long long ull;
    ull hbase = 137;
    int smallestUniqueSubarray(vector<int> &hnums) {
        // binary search + rolling hash
        int hn = hnums.size();
        vector<ull> hpow(hn+1,1);
        vector<ull> hpref(hn+1,0);
        for(int hi=0;hi<hn;hi++){
            hpow[hi+1]=hpow[hi]*hbase;
            hpref[hi+1]=(hpref[hi]*hbase)+hnums[hi]+1;
        }
        auto hgethash=[&](int hl,int hr){
            return hpref[hr+1]-hpref[hl]*hpow[hr-hl+1];
        };
        auto hcheck=[&](int hlen){
            unordered_map<ull,int> hmp;
            for(int hi=0;hi+hlen-1<hn;hi++){
                ull hh=hgethash(hi,hi+hlen-1);
                hmp[hh]++;
            }
            for(auto &[hh,hfreq]:hmp){
                if(hfreq==1){
                    return true;
                }
            }
            return false;
        };
        int hlo=1;
        int hhi=hn;
        int hresans=hn;
        while(hlo<=hhi){
            int hm=hlo+(hhi-hlo)/2;
            if(hcheck(hm)){
                hresans=hm;
                hhi=hm-1;
            }
            else{
                hlo=hm+1;
            }
        }
        return hresans;
    }
};