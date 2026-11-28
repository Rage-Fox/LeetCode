class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& hitems, int hbudget) {
        int hn = hitems.size();
        vector<int> hfreq(hn + 1, 0);
        long long hcheap = LLONG_MAX;
        for (auto& it : hitems) {
            hfreq[it[0]]++;
            hcheap = min(hcheap, (long long)it[1]);
        }
        vector<long long> hmulp(hn + 1, 0);
        for (int f = 1; f <= hn; f++) {
            for (int m = f; m <= hn; m += f) {
                hmulp[f] += hfreq[m];
            }
        }
        vector<pair<long long, long long>> hsp;
        for (auto& it : hitems) {
            int factor = it[0];
            long long price = it[1];
            long long d = hmulp[factor] - 1;
            if (price < 2 * hcheap && d > 0) {
                hsp.push_back({price, d});
            }
        }
        sort(hsp.begin(), hsp.end());
        long long spent = 0;
        long long total = 0;
        long long rem = hbudget;
        for (auto it : hsp) {
            long long take = min(it.second, rem / it.first);
            rem -= take * it.first;
            spent += take * it.first;
            total += 2 * take;
        }
        total += rem / hcheap;
        return total;
    }
};