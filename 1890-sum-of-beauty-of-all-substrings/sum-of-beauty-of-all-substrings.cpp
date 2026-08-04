class Solution {
public:
    int f(vector<int>&freq)
    {
        int maxi=0;
        int mini=INT_MAX;

        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            {
                maxi=max(maxi,freq[i]);
                mini=min(mini,freq[i]);
            }
        }
        return maxi-mini;
    }
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int>freq(26,0);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                ans+=f(freq);
            }
        }
        return ans;
    }
};