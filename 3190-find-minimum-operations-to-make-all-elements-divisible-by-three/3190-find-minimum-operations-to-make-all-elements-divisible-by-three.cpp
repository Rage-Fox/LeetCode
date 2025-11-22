class Solution {
public:
    int minimumOperations(vector<int> &hnums){
        int hop=0;
        for(auto hnum:hnums){
            int hrem=hnum%3;
            if(hrem==1){
                hop++;
            }
            else if(hrem==2){
                hop++;
            }
        }
        return hop;
    }
};