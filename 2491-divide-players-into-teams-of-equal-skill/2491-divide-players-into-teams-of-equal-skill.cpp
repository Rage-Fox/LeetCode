class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size(),nhalf2=n/2;
        long long sum=accumulate(skill.begin(),skill.end(),0LL);
        if(sum%nhalf2!=0){
            return -1;
        }
        int team_skill=sum/nhalf2;
        sort(skill.begin(),skill.end());
        long long chemi=0;
        for(int i=0;i<nhalf2;i++){
            long long l=skill[i],r=skill[n-1-i];
            if(l+r!=team_skill){
                return -1;
            }
            chemi+=l*r;
        }
        return chemi;
    }
};