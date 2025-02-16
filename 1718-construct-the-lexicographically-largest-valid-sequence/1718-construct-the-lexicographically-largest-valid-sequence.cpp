class Solution {
public:
    int n;
    vector<bool> used;
    bool backtrack(vector<int> &seq,int pos){
        if(pos==seq.size()){
            return true;
        }
        if(seq[pos]!=0){
            return backtrack(seq,pos+1);
        }
        // Try numbers from n down to 1 to ensure lexicographically largest
        for(int i=n;i>=1;i--){
            if(used[i]){
                continue;
            }
            // Number 1 only needs to be placed once
            if(i==1){
                seq[pos]=1;
                used[1]=true;
                if(backtrack(seq,pos+1)){
                    return true;
                }
                // If not successful, return to initial state (backtrack)
                seq[pos]=0;
                used[1]=false;
            } 
            // For Number>=2, we need to place it twice in array with distance exactly i
            else {
                // Check if the second position is valid
                if(pos+i<seq.size() and seq[pos+i]==0){
                    seq[pos]=i;
                    seq[pos+i]=i;
                    used[i]=true;
                    if(backtrack(seq,pos+1)){
                        return true;
                    }
                    // If not successful, return to initial state (backtrack)
                    seq[pos]=0;
                    seq[pos+i]=0;
                    used[i]=false;
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        this->n=n;
        int len=2*n-1;
        vector<int> seq(len,0);
        used.assign(n+1,false);
        backtrack(seq,0);
        return seq;
    }
};