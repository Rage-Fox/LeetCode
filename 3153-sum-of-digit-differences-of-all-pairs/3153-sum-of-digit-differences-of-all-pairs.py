class Solution:
    def sumDigitDifferences(self, nums: List[int]) -> int:
        nums=[str(num) for num in nums]
        num_len=len(nums[0])
        n=len(nums)
        total=0
        for i in range(num_len):
            digit=[0]*10
            for num in nums:
                digit[int(num[i])]+=1
            diff=0
            for d in digit:
                if d>0:
                    diff+=(d*(n-d))
            total+=diff
        return total//2