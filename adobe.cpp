#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // dp[k][r1][r2] stores the maximum friendliness when Lila is at (r1, k - r1) and Ravi is at (r2, k - r2)
    // k represents the sum of row and column indices (r + c)
    // r1 and r2 are row indices
    vector<vector<vector<int>>> dp(m + n, vector<vector<int>>(m, vector<int>(m, -1)));

    dp[0][0][0] = grid[0][0];

    for (int k = 1; k < m + n - 1; ++k) {
        for (int r1 = 0; r1 < m; ++r1) {
            for (int r2 = 0; r2 < m; ++r2) {
                int c1 = k - r1;
                int c2 = k - r2;

                if (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n) continue;

                int current_val = grid[r1][c1];
                if (r1 != r2 || c1 != c2) {
                    current_val += grid[r2][c2];
                }

                int max_prev_dp = -1;

                // Lila (r1, c1) from (r1-1, c1) or (r1, c1-1)
                // Ravi (r2, c2) from (r2-1, c2) or (r2, c2-1)

                // Case 1: Lila from (r1-1, c1), Ravi from (r2-1, c2)
                if (r1 > 0 && r2 > 0 && dp[k - 1][r1 - 1][r2 - 1] != -1) {
                    max_prev_dp = max(max_prev_dp, dp[k - 1][r1 - 1][r2 - 1]);
                }
                // Case 2: Lila from (r1-1, c1), Ravi from (r2, c2-1)
                if (r1 > 0 && c2 > 0 && dp[k - 1][r1 - 1][r2] != -1) {
                    max_prev_dp = max(max_prev_dp, dp[k - 1][r1 - 1][r2]);
                }
                // Case 3: Lila from (r1, c1-1), Ravi from (r2-1, c2)
                if (c1 > 0 && r2 > 0 && dp[k - 1][r1][r2 - 1] != -1) {
                    max_prev_dp = max(max_prev_dp, dp[k - 1][r1][r2 - 1]);
                }
                // Case 4: Lila from (r1, c1-1), Ravi from (r2, c2-1)
                if (c1 > 0 && c2 > 0 && dp[k - 1][r1][r2] != -1) {
                    max_prev_dp = max(max_prev_dp, dp[k - 1][r1][r2]);
                }

                if (max_prev_dp != -1) {
                    dp[k][r1][r2] = max_prev_dp + current_val;
                }
            }
        }
    }

    cout << dp[m + n - 2][m - 1][m - 1] << endl;

    return 0;
}
