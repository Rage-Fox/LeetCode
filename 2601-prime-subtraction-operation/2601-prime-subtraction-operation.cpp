class Solution {
public:
    vector<int> sieve(int n){
        vector<int> v(n+1),ans;
        for(int i=2;i<=sqrt(n);i++){
            if(!v[i]){
                for(int j=i*i;j<=n;j+=i){
                    v[j]=1;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(!v[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<int> p=sieve(1000);
        int n=nums.size(),last=nums.back();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<last){
                last=nums[i];
            }
            else{
                int pos=lower_bound(p.begin(),p.end(),nums[i])-p.begin()-1,f=0;
                for(int j=0;j<=pos;j++){
                    if(nums[i]-p[j]<last){
                        last=nums[i]-p[j];
                        f=1;
                        break;
                    }
                }
                if(!f){
                    return false;
                }
            }
        }
        return true;
    }
};