class Solution {
public:
    bool canJump(vector<int>& nums) {
        int hcurr=nums[0];
        for(int i=1;i<nums.size();i++){
            if(hcurr==0){
                return false;
            }
            hcurr--;
            hcurr=max(hcurr,nums[i]);
        }
        return true;
    }
};