class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp;
        k=k%n;
        for(int i=n-k;i<n;i++)
        {
            temp.push_back(nums[i]);
        }
        temp.insert(temp.end(),nums.begin(),nums.begin()+(n-k));
        nums=temp;
    }
};