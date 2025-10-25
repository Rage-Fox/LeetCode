class Solution {
public:
    int totalMoney(int n) {
      // https://www.youtube.com/watch?v=tKK7gvPCQfs
      int weeks=n/7;
      int low=28,high=28+(7*(weeks-1));
      int res=(weeks*(low+high)/2);
      int monday=weeks+1;
      for(int i=0;i<n%7;i++){
        res+=i+monday;
      }
      return res;
    }
};