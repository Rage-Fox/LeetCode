class Solution:
    def minimumPushes(self, hw: str) -> int:
        if len(hw)<=8:
            return len(hw)
        else:
            hn=len(hw)
            f=1
            s=0
            while hn:
                if hn>=8:
                    s+=(8*f)
                    hn-=8
                else:
                    s+=(hn*f)
                    hn=0
                f+=1
            return s