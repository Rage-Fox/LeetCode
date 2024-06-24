class Solution {
public:
    int minKBitFlips(vector<int> &nums,int k){
        int n=nums.size(),flipped=0,res=0;
        // Toggling the values where we flipped
        vector<int> isFlipped(n,0);
        for(int i=0;i<n;i++){
            // Checking if the previous k window has been flipped which will affect the current flip
            if(i>=k){
                flipped^=isFlipped[i-k];
            }
            // flipped denotes if 0, we need to flip. If 1, then while 0 was flipped, this 
            if(flipped==nums[i]){
                // Not possible case
                if(i+k>n){
                    return -1;
                }
                // Storing current 0/1 flip. 1 is based on previous iteration
                isFlipped[i]=1;
                // In the current k window, we don't need to flip 0's. All we have to flip is 1's as they turn into 0's
                flipped^=1;
                res++;
            }
        }
        return res;
    }
};