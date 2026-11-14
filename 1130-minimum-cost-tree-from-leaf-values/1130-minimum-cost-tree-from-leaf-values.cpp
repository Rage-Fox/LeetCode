class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        st.push(1e9);
        int ans = 0;
        for (int it : arr) {
            while (it >= st.top()) {
                int topp = st.top();
                st.pop();
                ans += topp * min(st.top(), it);
            }
            st.push(it);
        }
        while (st.size() > 2) {
            int topp = st.top();
            st.pop();
            ans += topp * st.top();
        }
        return ans;
    }
};