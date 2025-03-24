class Solution {
public:
    int countDays(int hdays,vector<vector<int>> &hmeetings) {
        if(hmeetings.empty())
            return hdays;
        sort(hmeetings.begin(),hmeetings.end());
        int hfree=0,hprev=0;
        for(auto hmeeting:hmeetings){
            int hs=hmeeting[0],he=hmeeting[1];
            if(hs>hprev+1){
                hfree+=(hs-hprev-1);
            }
            hprev=max(hprev,he);
        }
        if(hprev<hdays){
            hfree+=(hdays-hprev);
        }
        return hfree;
    }
};