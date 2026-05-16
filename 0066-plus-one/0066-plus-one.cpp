class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]<9){
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        // after this loop, the entire number just became from 9999 to 0000, we just need to add 1 infront
        vector<int> result(n+1,0);
        result[0]=1;
        return result;
    }
};