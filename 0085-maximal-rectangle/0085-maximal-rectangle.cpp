class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (auto& row : matrix) {
            for (int j = 0; j < m; j++) {
                heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestArea(heights));
        }
        return maxArea;
    }

    int largestArea(vector<int>& h) {
        h.push_back(0);
        stack<int> s;
        int maxA = 0;
        for (int i = 0; i < h.size(); i++) {
            while (!s.empty() && h[s.top()] >= h[i]) {
                int height = h[s.top()]; s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxA = max(maxA, height * width);
            }
            s.push(i);
        }
        return maxA;
    }
};