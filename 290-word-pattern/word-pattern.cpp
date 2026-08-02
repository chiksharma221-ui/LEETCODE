class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>a;
        unordered_map<string,char>b;
        int n=pattern.size();
        int m=s.size();
        vector<string>ans;
        
        string temp="";
        for(char ch:s)
        {
            if(ch==' ')
            {
                ans.push_back(temp);
                temp="";
            }
            else temp+=ch;
        }
        ans.push_back(temp);
        if(pattern.size() != ans.size())
        return false;
        for(int i=0;i<n;i++)
        {
            if(a.count(pattern[i]) && a[pattern[i]]!=ans[i])
            return false;

            if(b.count(ans[i]) && b[ans[i]]!=pattern[i])
            return false;

            a[pattern[i]]=ans[i];
            b[ans[i]]=pattern[i];
        }
        return true;
    }
};