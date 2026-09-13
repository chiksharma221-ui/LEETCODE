class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi=-1e9;
        int first=0,second=0;
        int n=nums.size();
        double sum=0;
        while(second<n)
        {
            sum+=nums[second];
            while(second-first+1>k)
            {
                sum-=nums[first];
                first++;
            }
            if(second-first+1==k)
            {
                maxi=max(maxi,(double)sum/k);
            }
            second++;
        }
        return maxi;
    }
};