class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int mini = 1e8;
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int u = matrix[i][j] + dp[i-1][j];
                int ld = 1e8 ;
                if (j > 0) 
                    ld=matrix[i][j] + dp[i-1][j-1];
                int rd = 1e8;
                 if (j < n - 1) 
                    rd =matrix[i][j] + dp[i-1][j+1];
                dp[i][j] =min(u,min(ld,rd));
            }
        }
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[m-1][j]);
        }
        return mini;
    }
};