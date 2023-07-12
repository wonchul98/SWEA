#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool print = false;
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
        int safe_cells = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (max_rows[i] == max_cols[j] && grid[i][j] == max_rows[i]) {
                    safe_cells++;
                }
            }
        }
        if (print)cout << "초기: " << safe_cells << endl;

        int64_t sum_safe_cells = 0; 
         
        while (Q--) {
            int r, c, x;
            cin >> r >> c >> x;
            r--; c--;
            int save_r = max_rows[r];
            int save_c = max_cols[c];
            max_rows[r] = max(max_rows[r], x);
            max_cols[c] = max(max_cols[c], x);

            
            int cnt = 0;
            if (save_c < x) {
                for (int i = 0; i <= r; i++) {
                    if (grid[i][c] == save_c && grid[i][c] == max_rows[i]) safe_cells--;
                }
            }
            if (save_r < x) {
                for (int j = 0; j <= r; j++) {
                    if (grid[r][j] == save_r && grid[r][j] == max_cols[j]) safe_cells--;
                }
            }

            //if (grid[r][c] == save_r && grid[r][c] == save_c) {//원래 안전지대 였던 경우
            //    if (print)cout << "case 1" << endl;
            //    for (int i = 0; i <= r; i++) {
            //        if (grid[i][c] == save_c && grid[i][c] == max_rows[i]) {
            //            cnt++;
            //        }
            //    }
            //    for (int j = 0; j <= c; j++) {
            //        if (grid[r][j] == save_r && grid[r][j] == max_cols[j]) {
            //            cnt++;
            //        }
            //    }
            //    safe_cells -= cnt;
            //    if (print)cout << "safe cells: " << safe_cells << endl;
            //}
            //else {//원래 안전지대가 아니였던 경우
            //    if (x > save_r && x > save_c) { //유일한 안전지대가 된 경우
            //        if (print)cout << "case 2" << endl;
            //        for (int i = 0; i <= r; i++) {
            //            if (grid[i][c] == save_c && grid[i][c] == max_rows[i]) {
            //                cnt++;
            //            }
            //        }
            //        for (int j = 0; j <= c; j++) {
            //            if (grid[r][j] == save_r && grid[r][j] == max_cols[j]) {
            //                cnt++;
            //            }
            //        }
            //        safe_cells = safe_cells - cnt + 1;
            //        if (print)cout << "safe cells: " << safe_cells << endl;
            //    }
            //    else if (x == max(save_r, save_c)) { // 전에 있던 안전지대와 같은 수가 된 경우
            //        if (print)cout << "case 3" << endl;
            //        if (x == save_r) {
            //            if (print)cout << "3_1" << endl;
            //            for (int i = 0; i <= r; i++) {
            //                if (print) cout << grid[i][c] << " " << r << " " <<save_c << endl;
            //                if (grid[i][c] == save_c && grid[i][c] == max_rows[i]) cnt++;
            //            }
            //        }
            //        else {
            //            if (print)cout << "3_2" << endl;
            //            for (int j = 0; j <= c; j++) {
            //                if (grid[r][j] == save_r && grid[r][j] == max_cols[j]) cnt++;
            //            }
            //        }
            //        safe_cells = safe_cells - cnt + 1;
            //        if (print)cout << "safe cells: " << safe_cells << endl;
            //    }
            //}
            //grid[r][c] = x;
            //sum_safe_cells += safe_cells;
        }

        cout << "#" << save - TC << " " << sum_safe_cells << endl;
    }
    return 0;
}