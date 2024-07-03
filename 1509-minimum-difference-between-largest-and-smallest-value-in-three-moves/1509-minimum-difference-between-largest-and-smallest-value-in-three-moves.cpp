class Solution {
public:
    int minDifference(vector<int>& nums) {
        // Given Hint: The minimum difference possible is obtained by removing three elements between the three smallest and three largest values in the array.
        sort(nums.begin(),nums.end());
        if(nums.size()<=4){
            return 0;
        }
        return min(nums[nums.size()-1]-nums[3],min(nums[nums.size()-4]-nums[0],min(nums[nums.size()-3]-nums[1],nums[nums.size()-2]-nums[2])));
    }
};