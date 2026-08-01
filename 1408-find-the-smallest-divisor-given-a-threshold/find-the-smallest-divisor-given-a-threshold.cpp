class Solution {
public:
    int find(vector<int>&nums,int divisor)
    {
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            total+=(nums[i]+divisor-1)/divisor;
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int start=1,end=*max_element(nums.begin(),nums.end());
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            int total=find(nums,mid);
            if(total<=threshold)
            {
                end=mid-1;
            }
            else start=mid+1;
        }
        return start;
    }
};