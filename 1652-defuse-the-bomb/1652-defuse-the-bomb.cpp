class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
		vector<int>ans(n,0);
		if(k==0)return ans;
		for(int i=0;i<n;i++){
			int count=0;
			if(k>0){
				for(int j=(i+1)%n;count<k;j=(j+1)%n){
					ans[i]+=code[j];
					count++;
				}
			}
			else{
				for(int j=i-1;count<abs(k);j--){
					if(j==-1){
                        j=n-1;
                    }
					ans[i]+=code[j];
					count++;
				}
			}
		}
		return ans;
    }
};