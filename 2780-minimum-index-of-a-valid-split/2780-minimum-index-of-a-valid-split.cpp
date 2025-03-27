class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size(),major=-1;
        unordered_map<int,int> m;
        for(int i:nums){
            m[i]++;
        }
        for(auto i:m){
            if(i.second*2>n){
                major=i.first;
            }
        }
        int cnt=0,t=m[major];
        for(int i=0;i<n;i++){
            if(nums[i]==major){
                cnt++;// Left Side Count of Split
                t--;// Right Side Count of Split
            }
            // Both side splits have major element
            if(cnt*2>i+1 and t*2>(n-i-1)){
                return i;
            }
        }
        return -1;
    }
};