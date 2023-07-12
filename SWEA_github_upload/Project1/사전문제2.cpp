#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("input/사전문제2_input.txt", "r", stdin);
    int TC;
    cin >> TC;
    int save = TC;
    while (TC--) {

        int N, M, Q;
        cin >> N >> M >> Q;

        vector<vector<int>> grid(N, vector<int>(M));
        vector<int> max_rows(N), max_cols(M);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
                max_rows[i] = max(max_rows[i], grid[i][j]);
                max_cols[j] = max(max_cols[j], grid[i][j]);
            }
        }

        int64_t sum_safe_cells = 0;
        while (Q--) {
            int r, c, x;
            cin >> r >> c >> x;
            r--; c--;

            max_rows[r] = max(max_rows[r], x);
            max_cols[c] = max(max_cols[c], x);
            grid[r][c] = x;
            cout << r << " " << c << " " << x <<  " " << max_rows[r] <<  " " << max_cols[c] << endl;
            int safe_cells = 0;
            for (int i = 0; i < N; i++) {
                if (max_rows[i] == max_cols[c] && grid[i][c] == max_cols[c]) {
                    cout << "(" << i << "," << c << ")" << endl;
                    safe_cells++;
                }
            }
            for (int j = 0; j < M; j++) {
                if (max_rows[r] == max_cols[j] && grid[r][j] == max_rows[r]) {
                    cout << "(" << r << "," << j << ")" << endl;
                    safe_cells++;
                }
            }
            safe_cells--;
            cout << safe_cells << endl;
            sum_safe_cells += safe_cells;
        }

        cout << "#" << save - TC << " " << sum_safe_cells << endl;
    }
    return 0;
}