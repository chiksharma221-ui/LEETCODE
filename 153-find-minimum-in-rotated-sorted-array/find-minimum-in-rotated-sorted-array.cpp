class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int n=nums.size();
        int start=0,end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[start]<=nums[end])
            {
                ans=min(ans,nums[start]);
                break;
            }
            if(nums[start]<=nums[mid])
            {
                ans=min(ans,nums[start]);
                start=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                end=mid-1;
            }
        }
        return ans;
    }
};