class Solution {
public:
    int minOperations(vector<int> &hnums){
        int hn=hnums.size(),hop=0;
        for(int hi=0;hi<=hn-3;hi++){
            if(hnums[hi]==0){
                hnums[hi]=(1-hnums[hi])&1;
                hnums[hi+1]=(1-hnums[hi+1])&1;
                hnums[hi+2]=(1-hnums[hi+2])&1;
                hop++;
            }
        }
        for(int hi=hn-2;hi<hn;hi++){
            if(hi>=0 && hnums[hi]==0){
                return -1;
            }
        }
        return hop;
    }
};