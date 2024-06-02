class Solution {
public:
    int minimumDifference(vector<int> &hnums,int hk){
        unordered_set<int> mpp;
        int ans=INT_MAX;
        for(auto e:hnums){
            unordered_set<int> nmpp;
            nmpp.insert(e);
            for(auto v:mpp)
                nmpp.insert((v&e));
            swap(nmpp,mpp);
            for(auto e:mpp)
                ans=min(ans,abs(e-hk));
        }
        return ans;
    }
};