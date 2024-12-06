class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int> mpp; 
        int s=0,c=0;
        for(auto it:banned){
            mpp[it]++;
        }
        for(int i=1;i<=n;i++){
            if(!mpp[i] and s+i<=maxSum){
                s+=i;
                c++;
            }
        }
        return c;
    }
};