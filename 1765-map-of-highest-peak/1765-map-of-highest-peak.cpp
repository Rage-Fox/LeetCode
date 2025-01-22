class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();
        vector<vector<int>> height(m,vector<int>(n,-1));
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    height[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto dir:directions){
                int newX=x+dir.first;
                int newY=y+dir.second;
                if(newX>=0 and newX<m and newY>=0 and newY<n and height[newX][newY]==-1){
                    height[newX][newY]=height[x][y]+1;
                    q.push({newX,newY});
                }
            }
        }
        return height;
    }
};