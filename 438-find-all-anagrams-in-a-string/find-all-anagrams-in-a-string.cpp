class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>freq1(256,0);
        vector<int>freq2(256,0);
        vector<int>result;

        int k=p.size();
        if(k>s.size())
            return result;
        for(char c : p)
            freq1[c-'a']++;
        for(int i=0;i<k;i++)
        {
            freq2[s[i]-'a']++;
        }
        if(freq1==freq2)
            result.push_back(0);

        for(int i=k;i<s.size();i++)
        {
            freq2[s[i]-'a']++;
            freq2[s[i-k]-'a']--;

            if(freq1==freq2)
            {
                result.push_back(i-k+1);
            }
        }
        return result;
    }
};