typedef long long ll;
class Solution {
public:
    ll maxSubarraySum(vector<int> &hnums,int hk){
        ll hn=hnums.size(),hresans=LLONG_MIN;
        vector<ll> hpre(hn+1,0);
        for(ll hi=0;hi<hn;hi++){
            hpre[hi+1]=hpre[hi]+hnums[hi];
        }
        vector<ll> hminn(hk,LLONG_MAX);
        for(ll hi=0;hi<=hn;hi++){
            ll hrem=hi%hk;
            if(hi>=hk){
                hresans=max(hresans,hpre[hi]-hminn[hrem]);
            }
            hminn[hrem]=min(hpre[hi],hminn[hrem]);
        }
        if(hresans==LLONG_MIN){
            return 0;
        }
        return hresans;
    }
};