class Solution {
public:
    bool isPrime(int num){
        if(num<=1){
            return false;
        }
        for(int i=2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int ans=0;
        string temp=to_string(n);
        reverse(temp.begin(),temp.end());
        int rev=stoi(temp);
        for(int i=min(n,rev);i<=max(n,rev);i++){
            if(isPrime(i)){
                ans+=i;
            }
        }
        return ans;
    }
};