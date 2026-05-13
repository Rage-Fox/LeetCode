class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int> line;
        for(auto &p:logs){
            line[p[0]]++;
            line[p[1]]--;
        }
        int max_p=0,ans_year,count=0;
        for(auto &i:line){
            count+=i.second;
            if(count>max_p){
                max_p=count;
                ans_year=i.first;
            }
        }
        return ans_year;
    }
};