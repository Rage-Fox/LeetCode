class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto &it:mpp){
            vector<int> &v=it.second;
            if(v.size()>=3){
                for(int i=0;i+2<v.size();i++){
                    int d=2*(v[i+2]-v[i]);
                    ans=min(ans,d);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};