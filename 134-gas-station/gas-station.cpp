class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int start=0;
        int currgas=0;
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            total+=gas[i]-cost[i];
            currgas+=gas[i]-cost[i];
            if(currgas<0)
            {
                start=i+1;
                currgas=0;
            }
        }
        if(total<0) return -1;
        else return start;
    }
};