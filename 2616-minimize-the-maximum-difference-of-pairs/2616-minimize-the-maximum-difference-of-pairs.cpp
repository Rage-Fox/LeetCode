class Solution {
public:
    bool helper(vector<int> &v,int m,int p) {
        int cnt = 0, mx = 0;
        for(int i = 1; i < v.size(); i += 1) {
            if(v[i] - v[i - 1] <= m) {
                i += 1;
                cnt += 1;
            }
        }
        return cnt >= p;
    }
    int minimizeMax(vector<int>& v, int p) {
        sort(v.begin(),v.end());
        int l = 0, r = v.back(), ans = -1;
        //v.back() means last element in the vector after sorting (maximum element)
        while(l<=r) {
            int m = (l + r)/2;
            if(helper(v,m,p)) {
                ans = m;
                r = m - 1;
            }
            else
                l = m + 1;
        }
        return ans;
    }
};