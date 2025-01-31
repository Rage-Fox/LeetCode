class DisjointSet {
public:
    vector<int> parent;
    vector<int> islandSize;
    DisjointSet(int n){
        parent.resize(n);
        islandSize.resize(n);
        for(int node=0;node<n;node++){
            // By default, each node is its own parent initially with size 1
            parent[node]=node;
            islandSize[node]=1;
        }
    }
    int findRoot(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findRoot(parent[node]);
    }
    void unionNodes(int nodeA,int nodeB){
        int rootA=findRoot(nodeA);
        int rootB=findRoot(nodeB);
        if(rootA==rootB){
            return;
        }
        if(islandSize[rootA]<islandSize[rootB]){
            // Attach rootA to rootB
            parent[rootA]=rootB;
            // Update size of rootB's island
            islandSize[rootB]+=islandSize[rootA];
        }
        else{
            // Attach rootB to rootA
            parent[rootB]=rootA;
            // Update size of rootA's island
            islandSize[rootA]+=islandSize[rootB];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        DisjointSet ds(rows*cols);
        vector<int> rowdirs={1,-1,0,0};
        vector<int> coldirs={0,0,1,-1};
        // Union adjacent 1's in the grid
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c]==1){
                    // Flatten 2D index to 1D
                    int currnode=(cols*r)+c;
                    for(int dir=0;dir<4;dir++){
                        int neigh_row=r+rowdirs[dir];
                        int neigh_col=c+coldirs[dir];
                        // Check bounds and ensure the neighbor is also 1
                        if(neigh_row>=0 and neigh_row<rows and neigh_col>=0 and neigh_col<cols and grid[neigh_row][neigh_col]==1){
                            int neighborNode=cols*neigh_row+neigh_col;
                            ds.unionNodes(currnode,neighborNode);
                        }
                    }
                }
            }
        }
        // Calculate the maximum possible island size
        int maxIslandSize=0;
        bool hasZero=false;
        unordered_set<int> uniqueRoots;
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++) {
                if(grid[r][c]==0){
                    hasZero=true;
                    // Start with the flipped 0
                    int currentIslandSize=1;
                    for(int dir=0;dir<4;dir++){
                        int neigh_row=r+rowdirs[dir];
                        int neigh_col=c+coldirs[dir];
                        // Check bounds and ensure the neighbor is 1
                        if(neigh_row>=0 and neigh_row<rows and neigh_col>=0 and neigh_col<cols and grid[neigh_row][neigh_col]==1){
                            int neighborNode=cols*neigh_row+neigh_col;
                            int root=ds.findRoot(neighborNode);
                            uniqueRoots.insert(root);
                        }
                    }
                    // Sum up the sizes of unique neighboring islands
                    for(int root:uniqueRoots){
                        currentIslandSize+=ds.islandSize[root];
                    }
                    // Clear the set for the next 0
                    uniqueRoots.clear();
                    maxIslandSize=max(maxIslandSize, currentIslandSize);
                }
            }
        }
        // If there are no zeros, the largest island is the entire grid
        if(!hasZero){
            return rows*cols;
        }
        return maxIslandSize;
    }
};