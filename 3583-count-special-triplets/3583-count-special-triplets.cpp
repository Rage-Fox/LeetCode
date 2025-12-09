class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod=1e9+7;
        unordered_map<int,int> suffix;
        unordered_map<int,int> prefix;
        for(auto x:nums){
            suffix[x]++;
        }
        long long ans=0;
        for(auto x:nums){
            suffix[x]--;
            ans+=(long long)prefix[2*x]*suffix[2*x];
            prefix[x]++;
        }
        return ans%mod;
    }
};