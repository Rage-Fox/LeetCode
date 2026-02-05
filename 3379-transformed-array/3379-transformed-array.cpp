class Solution {
public:
    vector<int> constructTransformedArray(vector<int> &hnums){
        int hn=hnums.size();
        vector<int> hresans(hn);
        for(int hi=0;hi<hn;hi++){
            if(hnums[hi]!=0){
                int hx=(hi+hnums[hi])%hn;
                if(hx<0){
                    hx+=hn;
                }
                hresans[hi]=hnums[hx];
            }
            else{
                hresans[hi]=hnums[hi];
            }
        }
        return hresans;
    }
};