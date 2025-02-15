class Solution {
public:
    // Number ranges from 1 to 1000 only
    bool CanPartition(int num,int target){
        // Invalid partition found
        if(target<0 or num<target){
            return false;
        }
        // Valid partition found
        if(num==target){
            return true;
        }
        // Recursively check all partitions for a valid partition
        return CanPartition(num/10,target-num%10) or
               CanPartition(num/100,target-num%100) or
               CanPartition(num/1000,target-num%1000);
    }
    int punishmentNumber(int n) {
        int punishmentNum=0;
        for(int currentNum=1;currentNum<=n;currentNum++){
            int squareNum=currentNum*currentNum;
            // Check if valid partition can be found and add squared number
            if(CanPartition(squareNum,currentNum)){
                punishmentNum+=squareNum;
            }
        }
        return punishmentNum;
    }
};