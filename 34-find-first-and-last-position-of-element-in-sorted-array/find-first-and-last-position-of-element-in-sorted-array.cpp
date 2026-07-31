class Solution {
public:
    int lb(vector<int>&nums,int target)
    {
        int n=nums.size();
        int start=0,end=n-1;
        int ans=n;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]>=target)
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }

    int ub(vector<int>&nums,int target)
    {
        int n=nums.size();
        int start=0,end=n-1;
        int ans=n;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(nums[mid]>target)
            {
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lb(nums,target);
        int last = ub(nums,target)-1;

        if(first==nums.size() || nums[first]!=target)
        return{-1,-1};
        vector<int>res(2,-1);
        res[0]=first;
        res[1]=last;
        return res;
    }

};