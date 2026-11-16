class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<long long> p;
        long long s = 0;
        // prefix sum
        for (int a : tasks) {
            s += a;
            p.push_back(s);
        }
        long long d = 0;
        vector<int> res;
        int n = tasks.size();
        for (int sh : shifts) {
            if (d + sh >= s) {
                res.push_back(0);
                d = 0;
            } else {
                d += sh;
                auto it = upper_bound(p.begin(), p.end(), d) - p.begin();
                res.push_back(n - it);
            }
        }
        return res;
    }
};