class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int pxor=0;
        for(int i=0;i<n;i++)
        {   
            pxor^=nums[i];
        }
        return pxor;
    }
};