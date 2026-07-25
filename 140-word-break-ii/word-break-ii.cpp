class Solution {
public:

    vector<string> ans;

    void solve(int index,string &s,
               unordered_set<string> &st,
               vector<string> &path)
    {
        if(index==s.size())
        {
            string sentence="";

            for(int i=0;i<path.size();i++)
            {
                sentence+=path[i];

                if(i!=path.size()-1)
                    sentence+=" ";
            }

            ans.push_back(sentence);
            return;
        }

        string word="";

        for(int i=index;i<s.size();i++)
        {
            word+=s[i];

            if(st.find(word)!=st.end())
            {
                path.push_back(word);

                solve(i+1,s,st,path);

                path.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st;

        for(auto word:wordDict)
            st.insert(word);

        vector<string> path;

        solve(0,s,st,path);

        return ans;
    }
};