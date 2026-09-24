class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
           if(self.digitsum(nums[i])==i):
            return i
        return -1

    def digitsum(self,n)->int:
        sum=0
        while n!=0:
            sum+=n%10
            n=n//10
        return sum
