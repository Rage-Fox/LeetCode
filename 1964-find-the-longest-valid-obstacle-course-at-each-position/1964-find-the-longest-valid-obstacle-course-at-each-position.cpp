class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> res(n,1);
        vector<int> l;
        l.push_back(obstacles[0]);
        for(int i=1;i<n;i++)
        {
            if(l.back()<=obstacles[i])
            {
                l.push_back(obstacles[i]);
                res[i]=l.size();
            }
            else
            {
                int idx=(upper_bound(l.begin(),l.end(),obstacles[i])-l.begin());
                l[idx]=obstacles[i];
                res[i]=idx+1;
            }
        }
        return res;
    }
};