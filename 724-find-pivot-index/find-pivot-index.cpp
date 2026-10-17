class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        int leftsum=0;
        for(int num:nums)
        {
            totalsum+=num;
        }
        for(int i=0;i<n;i++)
        {
            int rightsum=totalsum-leftsum-nums[i];
            if(leftsum==rightsum)
                return i;
            
            leftsum+=nums[i];
        }
        return -1;
    }
};