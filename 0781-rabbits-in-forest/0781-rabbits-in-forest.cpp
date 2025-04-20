class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // If a rabbit says x, it implies a group of (x + 1) rabbits of that color
        int ans=0;
        unordered_map<int,int>mpp;
        for(auto it:answers){
            mpp[it]++;
        }
        for(auto it:mpp){
            int size=it.first+1;
            int num=it.second/size;
            if(it.second%size){
                num++;
            }
            ans+=(num*size);
        }
        return ans;
    }
};