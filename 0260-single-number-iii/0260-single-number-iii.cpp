class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for(auto i:nums)
            x^=i;
        // Performing full XOR for the entire nums array
        int n=nums.size();
        int ind=0;
        // Now, we have to look for the left-most set bit's index
        while(x){
            if(x&1)
                break;
            ind++;
            x=x>>1;
        }
        int xor1=0,xor2=0;
        // Based on the set bit a that particular position, divide into two different sets and perform XOR for each set
        for(int i=0;i<n;i++){
            if(nums[i]&(1<<ind))
                xor1^=nums[i];
            else
                xor2^=nums[i];
        }
        // Return the answer XOR1 and XOR2 in any order!
        return {xor1,xor2};
    }
};