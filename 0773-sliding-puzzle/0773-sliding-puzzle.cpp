class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start="";
        for(auto row:board){
            for(int num:row){
                start+=to_string(num);
            }
        }
        string target="123450";
        // If 0 is in ith position, then these are the possible positions you can swap 0 with!
        vector<vector<int>> neighbors={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        queue<pair<string,int>> q;
        unordered_set<string> visited;
        q.push({start,0});
        visited.insert(start);
        while(!q.empty()){
            auto [current,moves]=q.front();
            q.pop();
            // 1st occurence is the fastest one with minimum moves
            if(current==target){
                return moves;
            }
            int zeroPos=current.find('0');
            for(int neighbor:neighbors[zeroPos]){
                // Swap
                swap(current[zeroPos],current[neighbor]);
                if(!visited.count(current)){
                    visited.insert(current);
                    q.push({current,moves+1});
                }
                // Unswap
                swap(current[zeroPos],current[neighbor]);
            }
        }
        return -1;
    }
};