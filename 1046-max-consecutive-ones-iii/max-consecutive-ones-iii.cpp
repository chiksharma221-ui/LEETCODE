class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int first=0,second=0,maxlen=0,zero=0;
        while(second<nums.size())
        {
            if(nums[second]==0) zero++;
            while(zero>k)
            {
                if(nums[first]==0)
                {
                    zero--;
                }
                first++;
            }
            if(zero<=k)
            {
                maxlen=max(maxlen,second-first+1);
            }
            second++;
        }
        return maxlen;
    }
};