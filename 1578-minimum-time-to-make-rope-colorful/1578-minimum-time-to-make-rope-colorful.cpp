class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum=0,n=colors.size();
        for(int i=0;i<n-1;i++){
            if(colors[i]==colors[i+1]){
                if(neededTime[i]<neededTime[i+1]){
                    sum=sum+neededTime[i];
                }
                else{
                    sum= sum +neededTime[i+1];
                    swap(neededTime[i],neededTime[i+1]);
                }
            }
        }  
        return sum;
    }
};