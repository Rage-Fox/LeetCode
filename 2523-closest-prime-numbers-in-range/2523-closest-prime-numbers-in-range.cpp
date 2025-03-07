class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(1000001,true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i*i<=1000000;i++){
            if(isPrime[i]){
                for(int j=i*i;j<=1000000;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        vector<int> primes;
        for(int i=left;i<=right;i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
        if(primes.size()<2){
            return {-1,-1};
        }
        int num1=0,num2=0,mini=INT_MAX;
        for(int i=0;i<primes.size()-1;i++){
            int diff=primes[i+1]-primes[i];
            if(diff<mini){
                mini=diff;
                num1=primes[i];
                num2=primes[i+1];
            }
        }
        return {num1, num2};
    }
};