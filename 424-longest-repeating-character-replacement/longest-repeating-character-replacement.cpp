class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int first=0,second=0;
        int maxlen=0,maxfreq=0;

        vector<int>freq(256,0);
        while(second<n)
        {
            freq[s[second]-'A']++;
            maxfreq=max(maxfreq,freq[s[second]-'A']);
            while((second-first+1)-maxfreq >k)
            {
                freq[s[first]-'A']--;
                first++;
                maxfreq=0;

                for(int i=0;i<26;i++)
                {
                    maxfreq=max(maxfreq,freq[i]);
                }
            }
            if((second-first+1)-maxfreq<=k)
            {
                maxlen=max(maxlen,second-first+1);
            }
            second++;
        }
        return maxlen;
    }
};