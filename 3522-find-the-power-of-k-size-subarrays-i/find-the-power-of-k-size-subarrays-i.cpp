class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        int index=0;
        int first=0,second=0;
        vector<int>ans;
        int maxi=-1e9;
        while(second<n)
        {
            while(second-first+1>k)
            {
                first++;
            }
            if(second-first+1==k)
            {
                bool valid=true;
                for(int i=first;i<second;i++)
                {
                    if(nums[i+1]!=nums[i]+1)
                    {
                        valid=false;
                        break;
                    }
                }
                if(valid) ans.push_back(nums[second]);
                else ans.push_back(-1);
            }
            second++;
        }
        return ans;
    }
};