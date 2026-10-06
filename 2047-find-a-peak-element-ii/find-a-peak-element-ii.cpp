class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int low = 0;
        int high = rows - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int bestcol = 0;
            for (int col = 1; col < cols; col++) {
                if (mat[mid][col] > mat[mid][bestcol]) {
                    bestcol = col;
                }
            }
            if (mat[mid][bestcol] > mat[mid + 1][bestcol]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        int bestCol = 0;

        for (int col = 1; col < cols; col++) {
            if (mat[low][col] > mat[low][bestCol]) {
                bestCol = col;
            }
        }

        return {low, bestCol};
    }
};