class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n=word.length();
        int ans=INT_MAX;
        vector<int>v(26,0);
        for(char &ch:word){
            v[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(v[i]==0){
                continue;
            }
            int curr=0;
            for(int j=0;j<26;j++){
                // If it is smaller just Delete it
                if(v[i]>v[j]){
                    curr+=v[j];
                }
                else if(abs(v[j]-v[i])>k){
                    curr+=abs(v[j]-v[i]-k);
                }
            }
            ans=min(ans,curr);
        }
        return ans;
    }
};