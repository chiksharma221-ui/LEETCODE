class Solution:
    def solve(self,n,index,flag,nums,dp):
        if index>=n:
            return 0
        if dp[index][flag]!=-1:
            return dp[index][flag]
        
        #pick
        if(flag==0):
            pick=nums[index]+self.solve(n,index+1,1,nums,dp)
        else:
            pick=-nums[index]+self.solve(n,index+1,0,nums,dp)

        #no pick
        nopick=self.solve(n,index+1,flag,nums,dp)

        dp[index][flag]=max(pick,nopick)
        return dp[index][flag]

    def maxAlternatingSum(self, nums: List[int]) -> int:
        n=len(nums)
        dp=[[-1]*2 for _ in range(n)]
        return self.solve(n,0,0,nums,dp)