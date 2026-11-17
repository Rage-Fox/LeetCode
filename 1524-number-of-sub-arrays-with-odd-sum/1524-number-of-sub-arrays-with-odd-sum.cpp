class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans=0,sum=0,evenSum=0,oddSum=0;
        int mod=1e9+7;
        for(int &num:arr){
            sum+=num;
            if(sum%2!=0){
                // If current prefix sum is odd, add the number of even subarrays
                oddSum++;
                ans+=((1+evenSum)%mod);
            }
            else{
                // If current prefix sum is even, add the number of odd subarrays
                evenSum++;
                ans=((ans+oddSum)%mod);
            }
        }
        return ans%mod;
    }
};