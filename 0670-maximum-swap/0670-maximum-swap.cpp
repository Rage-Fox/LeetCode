class Solution {
public:
    int maximumSwap(int num) {
        string numStr=to_string(num);
        int n=numStr.length();
        int last[10]={};
        for(int i=0;i<n;i++){
            last[numStr[i]-'0']=i;
        }
        for(int i=0;i<n;i++){
            // Our target is to swap with the maximum so start from 9 to current number
            for(int d=9;d>numStr[i]-'0';d--){
                // Our intention is to make maximum number. So we always have to swap 'i' with index '>i'
                // Our assumption is that index 'i' is having small number and index '>i' is having large number
                if(last[d]>i){
                    swap(numStr[i],numStr[last[d]]);
                    return stoi(numStr);
                }
            }
        }
        return num;
    }
};