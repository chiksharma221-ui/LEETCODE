class Solution {
public:
    int kadanemax(vector<int>&nums,int n)
    {
        int maxi=INT_MIN;
        int prefix=0;
        for(int i=0;i<n;i++)
        {
            prefix+=nums[i];
            maxi=max(maxi,prefix);
            if(prefix<0) prefix=0;
        }
        return maxi;
    }
    int kadanemin(vector<int>&nums,int n)
    {
        int mini=INT_MAX;
        int suffix=0;
        for(int i=0;i<n;i++)
        {
            suffix+=nums[i];
            mini=min(mini,suffix);
            if(suffix>0) suffix=0;
        }
        return mini;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int maxsum=kadanemax(nums,n);
        int minsum=kadanemin(nums,n);

        return max(maxsum,abs(minsum));
    }
};