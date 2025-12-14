class Solution {
public:
    int numberOfWays(string corridor) {
        const int mod=1e9+7;
        vector<int> seats;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                seats.push_back(i);
            }
        }
        int s=seats.size();
        if(s==0 || s&1){
            return 0;
        }
        int ans=1;
        for(int i=2;i<s;i+=2){
            ans=(1LL*ans)%mod*(seats[i]-seats[i-1])%mod;
            ans%=mod;
        }
        return ans;
    }
};