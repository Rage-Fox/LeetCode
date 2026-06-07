class Solution {
public:
    long long maxTotal(vector<int>& hnums, string hstr) {
        int hn = hnums.size();
        long long hresans=0;
        for(int hi=0;hi<hn;hi++){
            if(hstr[hi]=='0'){
                continue;
            }
            long long hs=hnums[hi],hminn=0,hstart=hi;
            if(hi>0){
                hs+=hnums[hi-1];
                hminn=min(hnums[hi-1],hnums[hi]);
            }
            while(hi+1<hn and hstr[hi+1]=='1'){
                hs+=hnums[hi+1];
                if(hstart>0){
                    hminn=min(hminn,(long long)hnums[hi+1]);
                }
                hi++;
            }
            hresans+=(hs-hminn);
        }
        return hresans;
    }
};