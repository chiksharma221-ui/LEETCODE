class Solution {
public:
    int findmax(vector<int>&piles)
    {
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            if(piles[i]>maxi)
            {
                maxi=max(maxi,piles[i]);
            }
        }
        return maxi;
    }
    long long find(vector<int>&piles,int hourly)
    {
        long long total=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            total+=ceil( (double)piles[i]/  (double)hourly);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1,end=findmax(piles);
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            long long total=find(piles,mid);
            if(total<=h) end=mid-1;
            else start=mid+1;
        }
        return start;
    }
};