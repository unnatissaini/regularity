class Solution {
public:
    vector<int> queens;

    int totalNQueens(int n) {
        queens.assign(10, -1);
        return backTrack(0, n);
    }

private:
    int backTrack(int row, int n) {
        // base case
        if (row == n) return 1;

        int ans = 0;
        for (int col = 0; col < n; col++) {
            if (feasible(row, col)) {
                queens[row] = col;

                ans += backTrack(row + 1, n);

                // backtracking
                queens[row] = -1;
            }
        }
        return ans;
    }

    bool feasible(int row, int col) {
        for (int i = 0; i < row; i++) {
            int prow = i;
            int pcol = queens[i];

            if (pcol == col || abs(col - pcol) == abs(prow - row))
                return false;
        }
        return true;
    }
};