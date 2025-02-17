class Solution {
public:
    unordered_set<string> res;
    void backtrack(string &tiles,int size,int mask,string ongoing){
        if(size==0){
            if(ongoing!=""){
                res.insert(ongoing);
            }
            return;
        }
        for(int i=0;i<tiles.size();i++){
            if(!(mask&(1<<i))){
                backtrack(tiles,size-1,mask|(1<<i),ongoing+tiles[i]);
            }
        }
    }
    int numTilePossibilities(string tiles) {
        for(int i=1;i<=tiles.size();i++){
            backtrack(tiles,i,0,"");
        }
        return res.size();
    }
};