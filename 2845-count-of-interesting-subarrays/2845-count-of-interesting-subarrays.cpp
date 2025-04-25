class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans=0;
        int n=nums.size(),cur=0;
        unordered_map<int,int> freq;
        freq[0]=1;
        for(int i=0;i<n;i++){
            cur+=nums[i]%modulo==k;
            ans+=freq[(cur-k+modulo)%modulo];
            freq[cur%modulo]++;
        }
        return ans;
    }
};