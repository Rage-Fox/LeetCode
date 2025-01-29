class Solution {
public:
    vector<int> parent;
    int findUltimateParent(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=findUltimateParent(parent[x]);
    }
    void unionGraph(int x,int y){
        int a=findUltimateParent(x);
        int b=findUltimateParent(y);
        parent[b]=parent[a];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size()+1);
        int ind=-1;
        for(int i=0;i<=edges.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            if(findUltimateParent(edges[i][0])!=findUltimateParent(edges[i][1]))
                unionGraph(edges[i][0],edges[i][1]);
            else{
                ind=i;
            }
        }
        return edges[ind];
    }
};