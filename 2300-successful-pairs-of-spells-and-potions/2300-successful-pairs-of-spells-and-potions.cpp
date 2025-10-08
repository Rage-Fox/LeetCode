class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>v;
        for(int i=0;i<spells.size();i++){
            int l=0,r=potions.size()-1;
            int idx=potions.size();// finding weakest potion(furthest left) that works
            while(l<=r){
                int m=(l+r)/2;
                if((long long)spells[i]*(long long)potions[m]>=success){
                    r=m-1;
                    idx=m;
                }
                else{
                    l=m+1;
                }
            }
            v.push_back(potions.size()-idx);
        }
        return v;
    }
};