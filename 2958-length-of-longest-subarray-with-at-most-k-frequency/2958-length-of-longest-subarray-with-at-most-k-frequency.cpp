class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        unordered_map<int,int> hmp;
        int hres = 0;
        while(r < n){
            hmp[nums[r]]++;
            if(hmp[nums[r]] > k){
                while(l<r and hmp[nums[r]] > k){
                    if(hmp[nums[l]] == 1)
                        hmp.erase(nums[l]);
                    else
                        hmp[nums[l]]--;
                    l++;
                }
            }
            hres = max(hres, r-l+1);
            r++;
        }
        return hres;
    }
};