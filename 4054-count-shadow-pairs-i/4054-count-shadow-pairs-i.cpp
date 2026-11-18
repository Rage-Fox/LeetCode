class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long ops = 0;
        stack<int> st;
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[i] < st.top()) {
                mpp[st.top()]--;
                st.pop();
            }
            // none of the nums[i] cannot form a pair with itself
            ops += (st.size() - mpp[nums[i]]);
            st.push(nums[i]);
            mpp[nums[i]]++;
        }
        return ops;
    }
};