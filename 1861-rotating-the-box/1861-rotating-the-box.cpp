class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size(),m=box[0].size();
        vector<vector<char>> new_box(m,vector<char>(n,'.'));
        for(int row=0;row<n;row++){
            int lowest_empty_cell=m-1;
            for(int col=m-1;col>=0;col--){
                if(box[row][col]=='*'){
                    new_box[col][n-1-row]='*';
                    lowest_empty_cell=col-1;
                }
                else if(box[row][col]=='#'){
                    swap(box[row][lowest_empty_cell],box[row][col]);
                    lowest_empty_cell--;
                }
            }
        }
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                new_box[col][n-1-row]=box[row][col];
            }
        }
        return new_box;
    }
};