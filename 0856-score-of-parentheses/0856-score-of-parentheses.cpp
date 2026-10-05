class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (char c : s) {
            if (c == '(') {
                st.push(0);
            }
            else {
                int curr = st.top();
                st.pop();
                // A  = () -> 1
                // (A) -> 2 * score(A)
                int value = (curr == 0) ? 1 : 2 * curr;
                int parent = st.top();
                st.pop();
                st.push(parent + value);
            }
        }
        return st.top();
    }
};