class Solution {
public:
    void rotate(vector<vector<int>>&mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(mat[i][j],mat[j][i]);
            }
        }

        for(int i=0;i<n;i++)
        {
            int start=0,end=n-1;
            while(start<end)
            {
                swap(mat[i][start],mat[i][end]);
                start++,end--;
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<4;i++)
        {
            if(mat==target)
            return true;
            rotate(mat);
        }
        return false;
    }
};