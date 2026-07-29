class Solution {
public:
    long long minimumSteps(string s) {
        int count=0;
        long long ans=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                ans+=i-count;//denotes how many places the zero has to travel
                count++;
            }
        }
        return ans;
    }
};