class Solution {
public:
    int numTeams(vector<int> &rating){
        int n=rating.size(),count=0;
        if(n<3){
            return 0;
        }
        int res=0;
        for(int i=1;i<n;i++){
            int prelarger=0,presmaller=0,postlarger=0,postsmaller=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]){
                    presmaller++;
                }
                else if(rating[j]>rating[i]){
                    prelarger++;
                }
            }
            for(int j=i+1;j<n;j++){
                if(rating[j]<rating[i]){
                    postsmaller++;
                }
                else if(rating[j]>rating[i]){
                    postlarger++;
                }
            }
            res+=presmaller*postlarger+prelarger*postsmaller;
        }
        return res;
    }
};