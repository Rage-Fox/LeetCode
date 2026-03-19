class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>> &hgrid){
        int hrows=hgrid.size();
        int hcols=hgrid[0].size();
        vector<vector<int>> hpreX(hrows+1,vector<int>(hcols+1,0));
        vector<vector<int>> hpreY(hrows+1,vector<int>(hcols+1,0));
        for(int i=1;i<=hrows;i++){
            for(int j=1;j<=hcols;j++){
                hpreX[i][j]=hpreX[i-1][j]+hpreX[i][j-1]-hpreX[i-1][j-1]+(hgrid[i-1][j-1]=='X'?1:0);
                hpreY[i][j]=hpreY[i-1][j]+hpreY[i][j-1]-hpreY[i-1][j-1]+(hgrid[i-1][j-1]=='Y'?1:0);
            }
        }
        int hansres=0;
        for(int i=0;i<hrows;i++){
            for(int j=0;j<hcols;j++){
                int hcx=hpreX[i+1][j+1]-hpreX[0][j+1]-hpreX[i+1][0]+hpreX[0][0];
                int hcy=hpreY[i+1][j+1]-hpreY[0][j+1]-hpreY[i+1][0]+hpreY[0][0];
                if(hcx==hcy and hcx>0){
                    hansres++;
                }
            }
        }
        return hansres;
    }
};