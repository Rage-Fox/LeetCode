class Solution {
public:
    int specialArray(vector<int>& nums) {
        int l=1,h=nums.size();
        while(l<=h){
            int mid=(l+h)/2,cnt=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>=mid)
                    cnt++;
            }
            if(mid==cnt)
                return mid;
            if(mid>cnt)
                h=mid-1;
            else
                l=mid+1;
        }
        return -1;
    }
};