class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        string ans(n,' ');
        unordered_map<char,int>freq;
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        for(auto &it : freq)
        {
            pq.push({it.second,it.first});
        }

        int index=n-1;
        while(!pq.empty())
        {
            int freq=pq.top().first;
            char ch=pq.top().second;
            pq.pop();

            while(freq--)
            {
                ans[index]=ch;
                index--;
            }
        }
        return ans;
    }
};