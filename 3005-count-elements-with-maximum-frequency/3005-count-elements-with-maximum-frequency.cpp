class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> frq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            frq[nums[i]]++;
        }
        int maxfreq=0;
        for(auto &p:frq){
            if(p.second>maxfreq){
                maxfreq=p.second;
            }
        }
        int totalsum=0;
        for(auto &p:frq){
            if(p.second==maxfreq){
                totalsum+=p.second;
            }
        }
        return totalsum;
    }
};