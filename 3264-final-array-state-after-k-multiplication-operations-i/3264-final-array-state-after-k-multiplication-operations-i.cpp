typedef long long ll;
class Solution {
public:
    vector<int> getFinalState(vector<int> &hnums,int hk,int hmultiplier) {
        int hn=hnums.size();
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        for(ll i=0;i<hn;i++){
            pq.push({hnums[i],i});
        }
        for(ll i=0;i<hk;i++){
            auto [hminn,hi]=pq.top();
            pq.pop();
            hnums[hi]=(hminn*hmultiplier);
            pq.push({hnums[hi],hi});
        }
        // for(ll i=0;i<hn;i++){
        //     hnums[i]%=hmod;
        // }
        return hnums;
    }
};