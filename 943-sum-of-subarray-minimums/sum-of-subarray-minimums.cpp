class Solution {
public:
    const int mod=1e9+7;
    vector<int>findpse(vector<int>&arr)
    {
        stack<int>s;
        int n=arr.size();
        vector<int>pse(n);
        for(int i=0;i<n;i++)
        {
            while(s.size()>0 && arr[s.top()]>arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                pse[i]=-1;
            }
            else{
                pse[i]=s.top();
            }
            s.push(i);
        }
        return pse;
    }
    vector<int>findnse(vector<int>&arr)
    {
        stack<int>s;
        int n=arr.size();
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--)
        {
            while(s.size()>0 && arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                nse[i]=n;
            }
            else{
                nse[i]=s.top();
            }
            s.push(i);
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>pse=findpse(arr);
        vector<int>nse=findnse(arr);

        long long ans=0;
        for(int i=0;i<arr.size();i++)
        {
            long long left=i-pse[i];
            long long right=nse[i]-i;

            ans=(ans+(left*right %mod) * arr[i])%mod;
        }
        return ans;
    }
};