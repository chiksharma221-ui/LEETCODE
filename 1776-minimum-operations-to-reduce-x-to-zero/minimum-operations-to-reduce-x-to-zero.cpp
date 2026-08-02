class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int targetsum=sum-x;
        if(targetsum==x) return n;
        if(targetsum<0) return -1;
        int currsum=0;
        int first=0,second=0;
        int ans=0;
        bool found=false;
        while(second<n)
        {
            currsum+=nums[second];
            while(currsum>targetsum)
            {
                currsum-=nums[first];
                first++;
            }
            if(currsum==targetsum)
            {
                found=true;
                ans=max(ans,second-first+1);
            }
            second++;
        }
        if(found)
        {
            return n-ans;
        }
        else return -1;
    }
};