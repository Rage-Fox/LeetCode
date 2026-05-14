class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size(),c=0;
        unordered_set<int> st;
        for(int x:nums){
            if(x==n-1){
                c++;
                if(c>2){
                    return false;
                }
                st.insert(x);
            }
            else if(x>=1 && x<n-1){
                st.insert(x);
            }
            else{
                return false;
            }
        }
        return st.size()==n-1 && c==2;
    }
};