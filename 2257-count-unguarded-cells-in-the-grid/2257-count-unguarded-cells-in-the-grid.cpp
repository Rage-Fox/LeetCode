class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        // Guards="2"
        for(int i=0;i<guards.size();i++){
            grid[guards[i][0]][guards[i][1]]=2;
        }
        // Walls="-2"
        for(int i=0;i<walls.size();i++){
            grid[walls[i][0]][walls[i][1]]=-2;
        }
        for(int i=0;i<guards.size();i++){
            int cx=guards[i][0],cy=guards[i][1];
            for(int i=cx+1;i<m;i++){
                if(grid[i][cy]==2 or grid[i][cy]==-2){
                    break;
                }
                // Guarded Cell will be represented as "1"
                grid[i][cy]=1;
            }
            for(int i=cx-1;i>=0;i--){
                if(grid[i][cy]==2 or grid[i][cy]==-2){
                    break;
                }
                grid[i][cy]=1;
            }
            for(int j=cy+1;j<n;j++){
                if(grid[cx][j]==2 or grid[cx][j]==-2){
                    break;
                }
                grid[cx][j]=1;
            }
            for(int j=cy-1;j>=0;j--){
                if(grid[cx][j]==2 or grid[cx][j]==-2){
                    break;
                }
                grid[cx][j]=1;
            }
        }
        int ct=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ct++;
                }
            }
        }
        return ct;
    }
};