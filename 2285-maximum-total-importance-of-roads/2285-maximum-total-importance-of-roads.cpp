class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads){
        // Intuition: City with highest number Of incoming edges gets highest importance or weight.
        vector<unordered_set<int>> graph(n);
        // Making a Bidirectional Graph
        for(int i=0;i<roads.size();i++){
            int f,s;
            f=roads[i][0];
            s=roads[i][1];
            graph[f].insert(s);
            graph[s].insert(f);
        }
        vector<pair<int,int>> imp(n);
        for(int i=0;i<n;i++){
            imp[i].first=graph[i].size();// Count of connected nodes
            imp[i].second=i;// Node Number
        }
        // Sorting based on connecting nodes less to more
        sort(imp.begin(),imp.end());
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            // Numbering less to more connecting nodes starting from "1"
            mpp[imp[i].second]=i+1;
        }
        long long ans=0;
        // Bidirectional sum
        for(int i=0;i<roads.size();i++){
            ans+=mpp[roads[i][0]];
            ans+=mpp[roads[i][1]];
        }
        return ans;
    }
};