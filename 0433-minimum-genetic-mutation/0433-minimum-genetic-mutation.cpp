class Solution {
public:
    bool isValidMutation(string mutatedString, string checker){
        int c=0;
        for(int i=0;i<8;i++){
            if(mutatedString[i]!=checker[i]){
                c++;
            }
        }
        return c==1;
    }
    int minMutation(string startGene, string endGene, vector<string> bank) {
        if(find(bank.begin(),bank.end(),endGene)==bank.end()){
            return -1;
        }
        queue<string> q;
        q.push(startGene);
        int iter=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto s=q.front();
                q.pop();
                if(s==endGene){
                    return iter;
                }
                int i=0;
                for(int i=0;i<bank.size();){
                    if(isValidMutation(s,bank[i])){
                        q.push(bank[i]);
                        bank.erase(bank.begin()+i);
                        continue;
                    }
                    i++;
                }
            }
            iter++;
        }
        return -1;
    }
};