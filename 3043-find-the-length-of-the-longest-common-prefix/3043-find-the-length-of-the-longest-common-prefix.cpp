class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> mp;
        // Storing prefixes for arr1
        for(auto it:arr1){
            string a=to_string(it);
            string x="";
            for(auto b:a){
                x+=b;
                mp[x]++;
            }
        }
        // Checking prefixes for arr1
        int ans=0;
        for(auto it:arr2){
            string a=to_string(it);
            string x="";
            for(auto b:a){
                x+=b;
                if(mp.find(x)!=mp.end()){
                    ans=max(ans,(int)x.size());
                }
            }
        }
        return ans;
    }
};