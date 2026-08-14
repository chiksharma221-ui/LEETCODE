class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int curr=0;
        vector<int>result(n);
        for(int i=0;i<n;i++)
        {
            int leftsum=curr;
            curr+=nums[i];
            int rightsum=sum-curr;
            result[i]=abs(rightsum-leftsum);
        }
        return result;
    }
};