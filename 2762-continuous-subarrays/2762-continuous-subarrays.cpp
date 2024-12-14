typedef long long ll;
class Solution {
public:
    ll continuousSubarrays(vector<int>& nums) {
        map<int,int> mpp;
        ll l=0,r=0,n=nums.size(),count=0;
        while(r<n){
            mpp[nums[r]]++;
            // Max-Min>2 then shrink the window
            while(mpp.rbegin()->first-mpp.begin()->first>2){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
};