class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mini = INT_MAX, idx = -1;
        for (int i = 0; i < drones.size(); i++) {
            int x = drones[i][0];
            int y = drones[i][1];
            int r = drones[i][2];
            int d = abs(x - target[0]) + abs(y - target[1]);
            if (r >= d) {
                if (d < mini || (d == mini && i < idx)) {
                    mini = d;
                    idx = i;
                }
            }
        }
        return idx;
    }
};