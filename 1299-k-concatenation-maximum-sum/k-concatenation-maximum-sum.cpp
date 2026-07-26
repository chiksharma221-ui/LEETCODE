class Solution {
public:
    int mod=1e9+7;
    int kadane(vector<int>&arr)
    {
        long long prefix=0;
        long long maxi=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            prefix+=arr[i];
            maxi=max(maxi,prefix);
            if(prefix<0) prefix=0;
        }
        return maxi;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        long long totalsum=0;
        for(int i=0;i<n;i++)
        {
            totalsum+=arr[i];
        }
        if(k==1) return kadane(arr)%mod;

        vector<int>twocopies=arr;
        twocopies.insert(twocopies.end(),arr.begin(),arr.end());
        long long maxsubarray=kadane(twocopies);
        if(totalsum>0)
        {
            maxsubarray+=(k-2)*totalsum;
        }
        
        return maxsubarray%mod;
    }
};