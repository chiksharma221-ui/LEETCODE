class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        bool found=false;
        for(auto &it : m)
        {
            if(it.second>1)
            found=true;
        }
        if(found)
            return true;
        else 
            return false;
    }
};