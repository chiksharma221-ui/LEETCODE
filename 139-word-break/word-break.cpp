class Solution {
public:
    bool f(int index,string&s,unordered_set<string>&st,vector<int>&dp)
    {
        if(index==s.size()) return true;
        if(dp[index]!=-1) return dp[index];
        
        string temp="";
        for(int i=index;i<s.size();i++)
        {
            temp+=s[i];
            if(st.find(temp)!=st.end())
            {
                if(f(i+1,s,st,dp))
                return dp[index]=true;
            }
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(int i=0;i<wordDict.size();i++)
        {
            st.insert(wordDict[i]);
        }
        vector<int>dp(s.size(),-1);
        return f(0,s,st,dp);
    }
};