class Solution {
public:
    int subArray(vector<int> &nums,int k){
        int count=0,ans=0,start=0,end=0,n=nums.size();
        while(end<n){
            if(nums[end]%2==1){
                count++;
            }
            while(count>k){
                if(nums[start]%2==1){
                    count--;
                }
                start++;
            }
            ans+=end-start+1;
            end++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums,int k){
        // Exactly k = Less than or equal to (k) - Less than or equal to (k-1)
        return subArray(nums,k)-subArray(nums,k-1);
    }
};