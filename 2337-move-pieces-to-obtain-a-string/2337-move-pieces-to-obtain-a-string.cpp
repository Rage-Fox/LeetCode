class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.size(),i=0,j=0;
        while(i<n or j<n){
            while(i<n and start[i]=='_'){
                i++;
            }
            while(j<n and target[j]=='_'){
                j++;
            }
            if(i==n or j==n){
                break;
            }
            if(start[i]==target[j]){
                if(start[i]=='L' and i<j){
                    return false;
                }
                else if(start[i]=='R' and i>j){
                    return false;
                }
            }
            else{
                return false;
            }
            i++;
            j++;
        }
        return (i==n and j==n);
    }
};