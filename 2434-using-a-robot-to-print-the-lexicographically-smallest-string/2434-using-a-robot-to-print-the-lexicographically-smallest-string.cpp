class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26);
        for (char c : s) freq[c - 'a']++;
        stack<char> st;
        string res = "";
        int minChar = 0;
        for (char c : s) {
            st.push(c);
            freq[c - 'a']--;
            while (minChar < 26 && freq[minChar] == 0) {
                minChar++;
            }
            while (!st.empty() && st.top() <= ('a' + minChar)) {
                res += st.top();
                st.pop();
            }
        }
        return res;
    }
};