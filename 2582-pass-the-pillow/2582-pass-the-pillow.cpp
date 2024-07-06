class Solution {
public:
    int passThePillow(int n, int time){
        if(n>time){
            return time+1;
        }
        int res=1;
        bool flag=true;
        while(time--){
            if(res==1){
                flag=true;
            }
            if(res==n){
                flag=false;
            }
            flag?res++:res--;
        }
        return res;
    }
};