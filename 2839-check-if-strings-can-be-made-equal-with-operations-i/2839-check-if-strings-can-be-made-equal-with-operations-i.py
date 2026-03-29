class Solution:
    def canBeEqual(self, st1: str, st2: str) -> bool:
        if(st1==st2):
            return True
        if(st1[2]+st1[1]+st1[0]+st1[3]==st2):
            return True
        if(st1[0]+st1[3]+st1[2]+st1[1]==st2):
            return True
        if(st1[2]+st1[3]+st1[0]+st1[1]==st2):
            return True
        return False