class Solution {
public:
    vector<int> sortJumbled(vector<int> &mapping,vector<int> &nums){
        vector<pair<int,int>> v;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            for(int j=0;j<s.length();j++){
                s[j]=mapping[s[j]-'0']+'0';
            }
            int n=stoi(s);
            v.push_back({n,i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            ans.push_back(nums[v[i].second]);
        }
        return ans;
    }
};