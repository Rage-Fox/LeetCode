typedef long long ll;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        // https://www.youtube.com/watch?v=B90kG-ZlptE
        // Prefix Sum on 1st row and 2nd row
        ll n=grid[0].size();
        vector<ll> presum1(n,0LL),presum2(n,0LL);
        presum1[0]=(ll)grid[0][0];
        presum2[0]=(ll)grid[1][0];
        for(ll i=1;i<n;i++){
            // cout<< presum1[i] << " " << presum2[i] << endl;
            presum1[i]+=presum1[i-1]+grid[0][i];
            presum2[i]+=presum2[i-1]+grid[1][i];
        }
        ll res=LLONG_MAX;
        for(ll i=0;i<n;i++){
            ll secondrobot=0;
            // We are calculating 2nd robot's probable path after 1st robot is done traversing
            // 1st row 2nd half remaining path & 2nd row 1st half remaining path
            if(i>0){
                secondrobot=max(presum1[n-1]-presum1[i],presum2[i-1]);
            }
            else{
                secondrobot=max(presum1[n-1]-presum1[i],0LL);
            }
            // Minimize the 2nd robot's points
            res=min(res,secondrobot);
        }
        return res;
    }
};