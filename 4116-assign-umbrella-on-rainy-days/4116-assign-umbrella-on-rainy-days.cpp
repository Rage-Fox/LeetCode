class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        vector<string> ans(n, "None");
        int count_a = 0, count_b = 0;
        for (int i = 0; i < n; ++i) {
            if (rain[i] == 0) {
                continue;
            }
            bool need_a = (i + 1 < n && rain[i + 1] == 1);
            if (need_a && count_a <= count_b) {
                ans[i] = "Alice";
                count_a++;
            } else {
                ans[i] = "Bob";
                count_b++;
            }
        }
        return ans;
    }
};