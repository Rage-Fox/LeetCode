class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<vector<int>> v;
        int n=queries.size();
        for(int i=0;i<n;i++){
            v.push_back({queries[i],i});
        }
        sort(v.begin(),v.end());
        sort(items.begin(),items.end());
        vector<int> ans(n);
        n=items.size();
        int maxx=0,j=0;
        for(auto i:v){
            while(j<n and items[j][0]<=i[0]){
                maxx=max(maxx,items[j][1]);
                j++;
            }
            ans[i[1]]=maxx;
        }
        return ans;
    }
};