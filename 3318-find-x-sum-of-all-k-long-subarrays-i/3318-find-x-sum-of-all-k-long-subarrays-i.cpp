class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(i>=k){
                if(--freq[nums[i-k]]==0){
                    freq.erase(nums[i-k]);
                }
            }
            if(i>=k-1){
                vector<pair<int,int>> v(freq.begin(),freq.end());
                sort(v.begin(),v.end(),[](auto &a,auto &b){
                    if(a.second!=b.second){
                        return a.second>b.second;
                    }
                    return a.first>b.first;
                });
                long long sum=0;
                for(int j=0;j<(int)v.size() && j<x;j++)
                    sum+=1LL*v[j].first*v[j].second;
                ans.push_back((int)sum);
            }
        }
        return ans;
    }
};