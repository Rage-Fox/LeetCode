class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int sz=strs[0].size(),answer=0;
        for(int col=0;col<sz;col++){
            for(int row=1;row<strs.size();row++){
                if(strs[row][col]<strs[row-1][col]){
                    answer++;
                    break;
                }
            }
        }
        return answer;
    }
};