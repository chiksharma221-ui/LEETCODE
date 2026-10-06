class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        int longest=1;
        int count=0;
        for(auto it : s)
        {
            if(s.find(it-1)==s.end())
            {
                count=1;
                int x=it;
                while(s.find(x+1) != s.end())
                {
                    x=x+1;
                    count=count+1;
                }
            }
            longest=max(longest,count);
        }
        return longest;
    }
};