class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq;
            unordered_map<int, int> pos;
            for (int j = i; j < n; j++) {
                int num = nums[j];
                if (pos.find(num) == pos.end()) {
                    pos[num] = freq.size();
                    freq.push_back(1);
                } else
                    freq[pos[num]]++;
                bool flag = true;
                for (int t = 0; t < freq.size(); t++) {
                    if (freq[t] != t + 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    cnt++;
            }
        }
        return cnt;
    }
};