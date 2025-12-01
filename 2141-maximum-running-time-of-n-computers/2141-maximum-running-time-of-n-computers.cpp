class Solution {
public:
    bool isPossible(vector<int> &batteries,long long mid,int n){
        long long m=batteries.size(),val=0,check=(long long)n*mid;
        for(int i=0;i<m;i++){
            if(batteries[i]<mid){
                val+=batteries[i];
            }
            else{
                val+=mid;
            }
        }
        if(val>=check){
            //if entire charge for all computers is drained, then we used all batteries, so it's a possible solution
            return true;
        }
        else{
            return false;
        }
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low = 0, high = 0;
        int si=batteries.size();
        for(int i=0;i<si;i++){
            high+=batteries[i];
        }
        long long ans=0;
        while(low<=high){   
            long long mid=low+(high-low)/2;
            if(isPossible(batteries, mid, n)){
                //asking for max minutes => increase the time to check if that's possible
                ans=mid;
                low=mid+1;
            }
            else{
                //if this particular time isn't possible, reduce the range to mid-1
                high=mid-1;
            }
        }
        return ans;
    }
};