class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // Sliding Window Approach
		// kmin: number of subarrays ending at last pos that contains minK
		// kmax: number of subarrays ending at last pos that contains maxK
		// start: pos of previous invalid number (namely > maxK or < minK)
        long long ans=0,kmin=0,kmax=0,start=-1;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(num<minK || num>maxK){
                kmin=0;
                kmax=0;
                start=i;
            }
            else{
                if(num==minK)
                    kmin=i-start;
                if(num==maxK)
                    kmax=i-start;       
                ans+=min(kmin,kmax);
            }
        }
        return ans;
    }
};