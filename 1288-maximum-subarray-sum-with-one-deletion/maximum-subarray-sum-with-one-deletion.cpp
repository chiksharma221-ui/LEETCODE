class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        vector<int>left(n);
        vector<int>right(n);

        left[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(arr[i],left[i-1]+arr[i]);
        }
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(arr[i],right[i+1]+arr[i]);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,left[i]);
        }
        for(int i=1;i<n-1;i++)
        {
            ans=max(ans,left[i-1]+right[i+1]);
        }
        return ans;
    }
};