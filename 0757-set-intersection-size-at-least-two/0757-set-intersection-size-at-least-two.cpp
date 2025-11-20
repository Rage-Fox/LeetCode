class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a, const vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            else{
                return a[0]<b[0];
            }
        });
        int n=intervals.size();
        set<int>st;
        for(int i=n-1;i>=0;i--){
            int c=0;
            for(auto x:st){
                if(x>=intervals[i][0] && x<=intervals[i][1]){
                    c++;
                }
            }
            if(c==1){
                st.insert(intervals[i][0]);
            }
            else if(c==0){
                st.insert(intervals[i][0]);
                st.insert(intervals[i][0]+1);
            }
        }
        return st.size();
    }
};