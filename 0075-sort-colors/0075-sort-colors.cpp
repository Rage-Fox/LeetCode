class Solution {
public:
    void sortColors(vector<int> &nums){
        unordered_map<int,int> numCount;
        for(int i=0;i<nums.size();i++){
            numCount[nums[i]]++;
        }
        int index=0;
        for(int i=0;i<numCount[0];i++){
            nums[index++]=0;
        }
        for(int i=0;i<numCount[1];i++){
            nums[index++]=1;
        }
        for(int i=0;i<numCount[2];i++){
            nums[index++]=2;
        }
    }
};