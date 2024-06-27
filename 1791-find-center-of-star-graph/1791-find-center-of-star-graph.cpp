class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mpp;
        int n=edges.size();
        for(int i=0;i<n;i++){
            mpp[edges[i][0]]++;
            mpp[edges[i][1]]++;
        }
        for(auto i:mpp){
            if(i.second==mpp.size()-1){
                return i.first;
            }
        }
        return 0;
    }
};