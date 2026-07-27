class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>prefix_counts;
        prefix_counts[0]=1;
        int currsum=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            currsum+=nums[i];
            if(prefix_counts.count(currsum-k))
            {
                count+=prefix_counts[currsum-k];
            }
            prefix_counts[currsum]++;
        }
        return count;
    }
};