class Solution {
public:
    vector<string> sortPeople(vector<string> &names,vector<int> &heights){
        int n=names.size();
        vector<pair<int,string>> hn(n);
        for(int i=0;i<n;i++){
            hn[i]={heights[i],names[i]};
        }
        sort(hn.rbegin(),hn.rend());
        for(int i=0;i<n;i++){
            names[i]=hn[i].second;
        }
        return names;
    }
};