class Solution {
public:
    int maximumLength(vector<int> &hnums, int hk){
        int hn=hnums.size();
        vector<vector<int>> hdp(hn,vector<int>(hk,1));
        int hmaxxPossAns=1;
        for(int hi=1;hi<hn;hi++){
            for(int hj=0;hj<hi;hj++){
                int hrem=(hnums[hi]+hnums[hj])%hk;
                if(hdp[hj][hrem]>0){
                    hdp[hi][hrem]=max(hdp[hi][hrem],hdp[hj][hrem]+1);
                    hmaxxPossAns=max(hmaxxPossAns,hdp[hi][hrem]);
                }
            }
        }
        return hmaxxPossAns;
    }
};