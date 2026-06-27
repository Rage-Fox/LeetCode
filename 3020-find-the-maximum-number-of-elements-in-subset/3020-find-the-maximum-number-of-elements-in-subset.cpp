class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        int ans = 1;
        // least possible result can be 1 as the array won't grow by powering up
        if (mp.count(1)) {
            int f = mp[1];
            if (f % 2 == 0)
                ans = max(ans, f - 1);
            else
                ans = max(ans, f);
        }
        vector<long long> keys;
        for (auto &it : mp) {
            keys.push_back(it.first);
        }
        for (long long cur : keys) {
            if (cur == 1)
                continue; // it is already calculated in above edge case
            long long temp = cur;
            int len = 0;
            // even count for left and right parts - same number 2 times
            while (true) {
                if (!mp.count(temp) || mp[temp] < 2)
                    break;
                len += 2;
                temp = temp * temp;
            }
            // middle number must be odd - repeating only once
            if (mp.count(temp) && mp[temp] == 1)
                len++;
            else
                len--; // as this is the last of sequence, we need only 1 number to be placed in middle
            ans = max(ans, len);
        }
        return ans;
    }
};