class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part)!=-1){
            int ind=s.find(part);
            s.erase(s.begin()+ind,s.begin()+ind+part.size());
        }
        return s;
    }
};