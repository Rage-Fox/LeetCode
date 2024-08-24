class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int alice=0, bob=0,size=piles.size();
        for(int i=0;i<size/2;i++){
            alice=alice+max(piles[i],piles[size-1-i]);
            bob=bob+min(piles[i],piles[size-1-i]);
        }
        if(alice>bob)  
            return true;
        return false;
    }
};