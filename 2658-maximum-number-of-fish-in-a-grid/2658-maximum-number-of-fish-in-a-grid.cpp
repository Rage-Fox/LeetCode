class Solution {
public:
    int dfs(int r,int c,vector<vector<int>> &vis,vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        int s=grid[r][c];
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int rr=r+row[i];
            int cc=c+col[i];
            if(rr>-1 and rr<n and cc>-1 and cc<m and !vis[rr][cc] and grid[rr][cc]){
                s+=dfs(rr,cc,vis,grid);
            }
        }
        return s;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]){
                    maxx=max(maxx,dfs(i,j,vis,grid));
                }
            }
        }
        return maxx;
    }
};