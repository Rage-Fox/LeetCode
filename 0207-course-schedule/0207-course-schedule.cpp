class Solution {
public:
    // imagine this code like a graph and check for cycles.
    bool cycleCheck(int src, vector<int>& pathVis, vector<int>& vis, vector<vector<int>>& courses) {
        vis[src] = 1;
        pathVis[src] = 1;
        for (auto child : courses[src]) {
            if (vis[child] != 1) {
                if (cycleCheck(child, pathVis, vis, courses)) {
                    return true;
                }
            } else if (pathVis[child]) {
                return true;
            }
        }
        pathVis[src] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses + 1);
        for (int i = 0; i < prerequisites.size(); i++) {
            courses[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(numCourses + 1, 0);
        vector<int> pathVis(numCourses + 1, 0);
        for (int i = 0; i <= numCourses; i++) {
            if (!vis[i] && courses[i].size()) {
                if (cycleCheck(i, pathVis, vis, courses)) {
                    return false;
                }
            }
        }
        return true;
    }
};