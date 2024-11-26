class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indeg(n,0);
        for(auto e:edges){
            int w=e[1];
            indeg[w]++;
        }
        vector<int> deg0;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                deg0.push_back(i);
            }
        }
        // Multiple Champions
        if(deg0.size()!=1){
            return -1;
        }
        return deg0[0];
    }
};