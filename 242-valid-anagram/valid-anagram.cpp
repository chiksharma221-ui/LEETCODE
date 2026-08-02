class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>freq1;
        

        int n=s.size();
        int m=t.size();
        for(int i=0;i<n;i++)
        {
            freq1[s[i]]++;
        }
        for(int i=0;i<m;i++)
        {
            freq1[t[i]]--;
        }

        for(auto &it:freq1)
        {
            if(it.second!=0) return 0;
        }
        return 1;
    }
};