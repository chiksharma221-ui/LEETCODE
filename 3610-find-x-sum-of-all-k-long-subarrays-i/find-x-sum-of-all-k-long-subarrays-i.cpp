class Solution {
public:
    int f(unordered_map<int,int>&mp,int x)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it : mp)
        {
            pq.push({it.second,it.first});

            if(pq.size()>x)
            pq.pop();
        }
        int sum=0;
        while(!pq.empty())
        {
            auto[freq,val]=pq.top();
            pq.pop();

            sum+=freq*val;
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0,j=0;
        vector<int>result;
        while(j<n)
        {
            mp[nums[j]]++;

            if(j-i+1==k)
            {
                result.push_back(f(mp,x));

                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};