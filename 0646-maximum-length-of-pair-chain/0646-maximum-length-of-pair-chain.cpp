class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Greedy (We can chose DP but it will be pick/notpick in recursion)
        sort(pairs.begin(),pairs.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int ans = 0, cur = -1e9;
        for (auto& pair : pairs) {
            if (pair[0] > cur) {
                cur = pair[1];
                ans++;
            }
        }
        return ans;
    }
};