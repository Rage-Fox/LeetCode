typedef long long ll;
class Solution {
public:
    int chalkReplacer(vector<int> &chalk,int k){
        ll totalChalk=0;
        for(int c:chalk){
            totalChalk=totalChalk+c;
        }
        k=k%totalChalk;
        for(int i=0;i<chalk.size();i++){
            if(chalk[i]>k){
                return i;
            }
            k=k-chalk[i];
        }
        return 0;
    }
};