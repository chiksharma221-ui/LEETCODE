class Solution {
public:
    bool solve(int idx,string &s,vector<int>&dp,unordered_set<string>&st)
    {
        if(idx==s.size())
            return true;
        if(dp[idx]!=-1)
            return dp[idx];
        if(st.find(s)!=st.end())
            return true;
        
        for(int i=1;i<=s.size();i++)
        {
            string temp=s.substr(idx,i);
            if(st.find(temp)!=st.end() && solve(idx+i,s,dp,st))
            {
                return dp[idx]=true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>st;
        for(string &word : wordDict)
        {
            st.insert(word);
        }
        vector<int>dp(n,-1);
        return solve(0,s,dp,st);
    }
};