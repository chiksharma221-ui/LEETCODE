class Solution {
public:
    string simplifyPath(string path) {
        string token="";
        stack<string>s;
        stringstream ss(path);
        while(getline(ss,token,'/'))
        {
            if(token=="." || token=="")
                continue;
            if(token!="..")
                s.push(token);
            else if(!s.empty())
                s.pop();
        }
        string res="";
        if(s.empty()) return "/";

        while(!s.empty())
        {
            res="/"+s.top()+res;
            s.pop();
        }
        return res;
    }
};