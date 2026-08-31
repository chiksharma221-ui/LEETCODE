class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left=1
        right=1
        i=0
        n=len(nums)
        j=n-1
        ans=[1]*n
        while i<n:
            ans[i]*=left
            left*=nums[i]

            ans[j]*=right
            right*=nums[j]

            i+=1
            j-=1
        return ans
            
        