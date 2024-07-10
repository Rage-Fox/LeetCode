class Solution {
public:
    int minOperations(vector<string> &logs){
        int lvl=0;
        for(string operation:logs){
            if(operation=="../"){
                lvl=max(0,lvl-1);
            }
            else if(operation=="./"){
                continue;
            }
            else{
                lvl++;
            }
        }
        return lvl;
    }
};