class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> res;
        res.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string temp=res.back();
            temp+='/';
            // used to compare a string or the part of string with another string or substring
            if(folder[i].compare(0,temp.size(),temp)!=0){
                res.push_back(folder[i]);
            }
        }
        return res;
    }
};