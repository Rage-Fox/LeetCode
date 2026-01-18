class Solution {
public:
    bool isMagic(vector<vector<int>> &g,vector<vector<int>> &r,vector<vector<int>> &c,int x,int y,int len){
        int target=r[x][y+len]-r[x][y];
        for(int i=0;i<len;i++){
            if(r[x+i][y+len]-r[x+i][y]!=target){
                return false;
            }
        }
        for(int j=0;j<len;j++){
            if(c[x+len][y+j]-c[x][y+j]!=target){
                return false;
            }
        }
        int d1=0,d2=0;
        for(int k=0;k<len;k++){
            d1+=g[x+k][y+k];
            d2+=g[x+len-1-k][y+k];
        }
        return d1==target && d2==target;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>> row(r,vector<int>(c+1,0));
        vector<vector<int>> col(r+1,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                row[i][j+1]=row[i][j]+grid[i][j];
            }
        }
        for(int j=0;j<c;j++){
            for(int i=0;i<r;i++){
                col[i+1][j]=col[i][j]+grid[i][j];
            }
        }
        int ans=1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int maxSize=min(r-i,c-j);
                for(int sz=maxSize;sz>ans;sz--){
                    if(isMagic(grid,row,col,i,j,sz)){
                        ans=sz;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};