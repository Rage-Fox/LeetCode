typedef long long ll;
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<ll> pref(n,0);
        pref[1]=1;
        for(int i=2;i<n;i++){
            if((ll)nums[i]-nums[i-1]<(ll)nums[i-1]-nums[i-2]){
                pref[i]=pref[i-1]+1;
            }
            else{
                pref[i]=pref[i-1]+(ll)nums[i]-nums[i-1];
            }
        }
        vector<ll> suff(n,0);
        suff[n-2]=1;
        for(int i=n-3;i>=0;i--){
            if((ll)nums[i+1]-nums[i]<=(ll)nums[i+2]-nums[i+1]){
                suff[i]=suff[i+1]+1;
            }
            else{
                suff[i]=suff[i+1]+(ll)nums[i+1]-nums[i];
            }
        }
        vector<int> ans;
        for(auto &v:queries){
            int l=v[0],r=v[1];
            if(l<r){
                ans.push_back(pref[r]-pref[l]);
            }
            else{
                ans.push_back(suff[r]-suff[l]);
            }
        }
        return ans;
    }
};