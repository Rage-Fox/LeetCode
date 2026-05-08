class Solution {
public:
    bool isPrime(int n){
        if(n==1){
            return 0;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return 0;
            }
        }
        return 1;
    }
    int minJumps(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        unordered_map<int,vector<int>> primeGroups;
        for(int i=0;i<n;i++){
            // Find all prime factors of nums[i]
            int num=nums[i];
            for(int p=2;p*p<=num;p++){
                if(num%p==0){
                    primeGroups[p].push_back(i);
                    while(num%p==0){
                        num/=p;
                    }
                }
            }
            if (num>1){
                primeGroups[num].push_back(i);
            }
        }
        // BFS
        queue<int> q;
        vector<bool> visited(n,false);
        unordered_set<int> usedPrimes;
        q.push(0);
        visited[0]=true;
        int jumps=0;
        while(!q.empty()){
            int size=q.size();
            jumps++;
            for(int i= 0;i<size;i++){
                int curr=q.front();
                q.pop();
                if(curr-1>=0 && !visited[curr-1]){
                    if(curr-1==n-1){
                        return jumps;
                    }
                    visited[curr-1]=true;
                    q.push(curr-1);
                }
                if(curr+1<n && !visited[curr+1]){
                    if(curr+1==n-1){
                        return jumps;
                    }
                    visited[curr+1]=true;
                    q.push(curr+1);
                }
                if(isPrime(nums[curr])){
                    int prime=nums[curr];
                    if(usedPrimes.find(prime)==usedPrimes.end()){
                        usedPrimes.insert(prime);
                        if(primeGroups.count(prime)){
                            for(int next:primeGroups[prime]){
                                if(next!=curr && !visited[next]){
                                    if(next==n-1){
                                        return jumps;
                                    }
                                    visited[next]=true;
                                    q.push(next);
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};