class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxarea = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int element = s.top();
                s.pop();

                int nse = i;
                int pse;
                if (s.empty()) {
                    pse = -1;
                } else {
                    pse = s.top();
                }
                maxarea = max(maxarea, heights[element] * (nse - pse - 1));
            }
            s.push(i);
        }
        while (!s.empty()) {
            int nse = n;
            int pse;
            int element = s.top();
            s.pop();
            if (s.empty()) {
                pse = -1;
            } else
                pse = s.top();

            maxarea = max(maxarea, heights[element] * (nse - pse - 1));
        }
        return maxarea;
    }
};