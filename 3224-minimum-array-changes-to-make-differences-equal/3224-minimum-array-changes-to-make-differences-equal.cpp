class Solution {
public:
    int minChanges(vector<int> &nums,int k){
        vector<pair<int,int>> diff;
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            int left=nums[i];
            int right=nums[n-i-1];
            int current_diff=abs(left-right);
            int max_change=max(max(left,right)-0,k-min(left,right));
            diff.push_back({current_diff,max_change});
            m[current_diff]++;
        }
        int max_freq=0,second_max_freq=0,max_diff=-1,second_max_diff=-1;
        for(auto &entry:m){
            if(entry.second>max_freq){
                second_max_freq=max_freq;
                second_max_diff=max_diff;
                max_freq=entry.second;
                max_diff=entry.first;
            }
            else if(entry.second>second_max_freq){
                second_max_freq=entry.second;
                second_max_diff=entry.first;
            }
        }
        int changes_max=0;
        int changes_second=0;
        for(auto &d:diff){
            if(d.first!=max_diff){
                if(d.second<max_diff) changes_max+=2;
                else changes_max++;
            }
            if(d.first!=second_max_diff){
                if(d.second<second_max_diff) changes_second+=2;
                else changes_second++;
            }
        }
        return min(changes_max,changes_second);
    }
};