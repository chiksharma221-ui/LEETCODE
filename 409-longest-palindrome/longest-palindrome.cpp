class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        unordered_map<char,int>freq;
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++;
        }
        bool oddfreq=0;
        int res=0;
        for(auto &it : freq)
        {
            if(it.second%2==0)
            res+=it.second;
            else{
                res+=it.second-1;
                oddfreq=1;
            }
        }
        if(oddfreq) res++;
        return res;
    }
};