class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        long long ans=LLONG_MIN;
        for(int end=max(0,n-k);end<n;end++){
            long long sum=0;
            for(int i= end;i>=0;i-=k){
                sum+=energy[i];
                ans=max(ans,sum);
            }
        }
        return (int)ans;
    }
};