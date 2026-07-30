class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi=-1e9;
        int i=0,j=0;
        int sum=0;
        int n=nums.size();
        while(j<n)
        {
            sum+=nums[j];
            //double avg;
            while(j-i+1>k)
            {
                sum-=nums[i];
                i++;
            }
            if(j-i+1==k)
            {
                maxi=max(maxi,(double)sum/k);
            }
            j++;
        }
        return maxi;
    }
};