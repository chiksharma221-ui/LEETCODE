class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        long long end=LLONG_MIN;
        int n=points.size();
        int burst=0;
        for(int i=0;i<n;i++)
        {
            if(end<points[i][0])
            {
                burst++;
                end=points[i][1];

            }
        }
        return burst;
    }
};