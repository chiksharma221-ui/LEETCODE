class Solution {
public:
    int f(int index,int previndex,vector<int>&nums,vector<vector<int>>&dp)
    {
        
        if(index==nums.size()) return 0;
        if(dp[index][previndex+1]!=-1) return dp[index][previndex+1];

        int nopick=f(index+1,previndex,nums,dp);
        int pick=0;
        if(previndex==-1 || nums[previndex]<nums[index])
        {
            pick=1+f(index+1,index,nums,dp);
        }
        return dp[index][previndex+1]=max(nopick,pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};