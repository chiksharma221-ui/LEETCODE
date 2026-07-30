class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=i;j<n;j++)
            {
                if(s[i]!=s[j])
                break;

                temp+=s[i];
                mp[temp]++;
            }
        }
        int ans=-1;
        for(auto &it : mp)
        {
            if(it.second>=3)
            {
                ans=max(ans,(int)it.first.size());
            }
        }
        return ans;
    }
};