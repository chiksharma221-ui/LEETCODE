class Solution {
public:
    vector<vector<int>>result;
    void solve(vector<int>&nums,vector<int>&ans)
    {
        if(nums.size()==0)
        {
            result.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            vector<int>remaining;
            for(int j=0;j<nums.size();j++)
            {
                if(j!=i)
                {
                    remaining.push_back(nums[j]);
                }
            }
            ans.push_back(x);
            solve(remaining,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ans;
        solve(nums,ans);
        return result;
    }
};