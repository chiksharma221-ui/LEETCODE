class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int countzero=0;
        int first=0,second=0;
        int n=nums.size();
        int ans=0;
        while(second<n)
        {
            if(nums[second]==0)
            countzero++;

            while(countzero>1)
            {
                if(nums[first]==0) countzero--;
                first++;
            }
            ans=max(ans,second-first+1-countzero);
            second++;
        }
        if(countzero==0) return n-1;
        else
        return ans;
    }
};