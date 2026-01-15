class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        def solvable(n):
            s=0
            t=1
            for i in range(len(n)-1):
                if n[i+1]-n[i]==1:
                    t+=1
                else:
                    s=max(s,t+1)
                    t=1
            s=max(s,t+1)
            return s
        hBars.sort()
        vBars.sort()
        ans=min(solvable(hBars),solvable(vBars))
        return ans*ans