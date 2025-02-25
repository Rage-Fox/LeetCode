class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans=0,sum=0,evenSum=0,oddSum=0;
        int mod=1e9+7;
        for(int &num:arr){
            sum+=num;
            if(sum%2!=0){
                oddSum++;
                ans+=((1+evenSum)%mod);
            }
            else{
                evenSum++;
                ans=((ans+oddSum)%mod);
            }
        }
        return ans%mod;
    }
};