class Solution {
public:
    int min_swaps(int tofind,vector<int> &arr1,vector<int> &arr2,int count){
        for(int i=1;i<arr1.size();i++){
            if(arr1[i]!=tofind && arr2[i]!=tofind){
                return INT_MAX;
            }
            if(arr1[i]==tofind){
                continue;
            }
            count++;
        }
        return count;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int ans=INT_MAX;
        ans=min(ans,min_swaps(tops[0],tops,bottoms,0)); // for tops[0] in tops
        ans=min(ans,min_swaps(tops[0],bottoms,tops,1)); // for tops[0] in bottoms
        ans=min(ans,min_swaps(bottoms[0],bottoms,tops,0)); // for bottoms[0] in bottoms
        ans=min(ans,min_swaps(bottoms[0],tops,bottoms,1)); // for bottoms[0] in tops
        return ans==INT_MAX?-1:ans;
    }
};