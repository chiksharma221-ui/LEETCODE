class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),comp);
        //int capacity=truckSize;
        int boxes=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            boxes=min(truckSize,boxTypes[i][0]);
            ans+=boxes*boxTypes[i][1];
            truckSize=truckSize-boxes;
            if(truckSize==0) break;
            
        }
        return ans;
    }
};