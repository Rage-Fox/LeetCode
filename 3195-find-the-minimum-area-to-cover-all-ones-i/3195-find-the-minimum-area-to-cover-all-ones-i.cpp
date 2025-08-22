class Solution {
public:
    int minimumArea(vector<vector<int>> &hgrid){
        int hnrow=hgrid.size(),hxrow=-1,hncol=hgrid[0].size(),hxcol=-1;
        for(int i=0;i<hgrid.size();i++){
            for(int j=0;j<hgrid[0].size();j++){
                if(hgrid[i][j]==1){
                    hnrow=min(hnrow,i);
                    hxrow=max(hxrow,i);
                    hncol=min(hncol,j);
                    hxcol=max(hxcol,j);
                }
            }
        }
        return (hxrow-hnrow+1)*(hxcol-hncol+1);
    }
};