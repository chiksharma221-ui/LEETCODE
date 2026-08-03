class Solution {
public:
    void rotate(string &s)
    {
        if(s.empty()) return ;
        char c=s[0];
        for(int i=1;i<s.size();i++)
        {
            s[i-1]=s[i];
        }
        s[s.size()-1]=c;
    }
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        for(int i=0;i<s.size();i++)
        {
            if(s==goal) return true;
            rotate(s);
        }
        return false;
    }
};