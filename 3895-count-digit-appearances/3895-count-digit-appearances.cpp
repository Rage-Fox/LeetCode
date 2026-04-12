class Solution {
public:
    int digitAppearance(int num,int digit){
        int count=0;
        while(num){
            if(num%10==digit){
                count++;
            }
            num/=10;
        }
        return count;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(auto it:nums){
            ans+=digitAppearance(it,digit);
        }
        return ans;
    }
};