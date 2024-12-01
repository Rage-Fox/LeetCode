class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<pair<int,int>>d={{-1,0},{0,1},{1,0},{0,-1}};
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        dp[0][0]=0;
        while(q.size()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto temp=q.front();
                q.pop();
                int x=temp.first,y=temp.second;
                for(auto it:d){
                    int nx=x+it.first;
                    int ny=y+it.second;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&dp[x][y]+grid[nx][ny]<dp[nx][ny]){
                        dp[nx][ny]=dp[x][y]+grid[nx][ny];
                        q.push({nx,ny});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};