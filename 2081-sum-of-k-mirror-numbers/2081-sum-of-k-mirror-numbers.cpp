class Solution {
public:
    bool ispal(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string tobasek(long long num,int k){
        string ans="";
        while(num>0){
            ans+=(char)('0'+ num%k);
            num/=k;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    long long kMirror(int k, int n) {
        long long sum=0;
        int count=0;
        //generate the base 10 pallindrome
        for(int len=1;count<n;len++){
            int start=pow(10,(len-1)/2);
            int end=pow(10,(len+1)/2);
            for(int i=start;i<end && count<n;i++){
                string s=to_string(i);
                string rev=s;
                reverse(rev.begin(),rev.end());
                string pal=(len%2==0) ? s+rev : s+rev.substr(1);
                long long num=stoll(pal);
                if(ispal(tobasek(num,k))){
                    sum+=num;
                    count++;
                }
            }
        }
        return sum;
    }
};