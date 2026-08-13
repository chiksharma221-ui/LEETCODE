class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int left=1;
        int right=1;
        int i=0;
        int j=n-1;
        vector<int>ans(n,1);
        while(i<n)
        {
            ans[i]*=left;
            left*=nums[i];

            ans[j]*=right;
            right*=nums[j];

            i++;
            j--;
        }
        return ans;
    }
};