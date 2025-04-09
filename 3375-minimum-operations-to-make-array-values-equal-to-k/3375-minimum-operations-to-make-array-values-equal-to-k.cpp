class Solution {
public:
    int minOperations(vector<int> &hnums,int hk){
        for(auto hit:hnums){
            if(hit<hk){
                return -1;
            }
        }
        unordered_set<int> hset;
        for(auto hit:hnums){
            if(hit>hk){
                hset.insert(hit);
            }
        }
        return hset.size();
    }
};