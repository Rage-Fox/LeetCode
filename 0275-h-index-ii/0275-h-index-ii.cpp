class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i,n=citations.size();
        for(i=n-1;i>=0;i--){
            if(citations[i]<n-i){
                break;
            }
        }
        return n-i-1;
    }
};