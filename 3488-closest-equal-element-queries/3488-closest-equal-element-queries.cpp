class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto &[i,pos]:mpp){
            int x=pos[0];
            // below operations are due to circular array
            pos.insert(pos.begin(),pos.back()-n); //insert last element at beginning
            pos.push_back(x+n); //insert first element at last
        }
        int m=queries.size();
        for(int i=0;i<m;i++){
            int x=nums[queries[i]];
            if(mpp[x].size()==3){ // 3 elements might be the same as we inserted two (first,last) in above loop
                queries[i]=-1;
                continue;
            }
            int pos=lower_bound(mpp[x].begin(),mpp[x].end(),queries[i])-mpp[x].begin();
            queries[i]=min(mpp[x][pos+1]-mpp[x][pos],mpp[x][pos]-mpp[x][pos-1]);
        }
        return queries;
    }
};