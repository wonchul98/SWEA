#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool print = true;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input/��������2_input.txt", "r", stdin);
    int TC;
    cin >> TC;
    int save = TC;
    while (TC--) {

        int N, M, Q;
        cin >> N >> M >> Q;

        vector<vector<int>> grid(N, vector<int>(M));
        vector<int> max_rows(N), max_cols(M);
        vector<int> rows(N), cols(M);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
                max_rows[i] = max(max_rows[i], grid[i][j]);
                max_cols[j] = max(max_cols[j], grid[i][j]);
            }
        }
        for (int i = 0; i < N; i++) rows[i] = -1;
        for (int i = 0; i < M; i++) cols[i] = -1;
        int safe_cells = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (max_rows[i] == max_cols[j]) {
                    safe_cells++;
                    rows[i] = j;
                    cols[j] = i;
                }
            }
        }
        if (print)cout << "�ʱ�: " << safe_cells << endl;

        int sum_safe_cells = 0;

        while (Q--) {
            cout << "1" << endl;
            int r, c, x;
            cin >> r >> c >> x;
            r--; c--;
            int save_r = max_rows[r];
            int save_c = max_cols[c];
            int save_x = grid[r][c];
            max_rows[r] = max(max_rows[r], x);
            max_cols[c] = max(max_cols[c], x);
            grid[r][c] = x;
            int cnt = 0;
            //���̱�
            
            cout << "2 " << endl;
            if (x > save_c) {//x�� save_c���� Ŀ�� 
                if (print) cout << "case 1" << endl;
                if (cols[c] != -1 && cols[c] != r) {//�ش� ���� �������� �ִ��� Ȯ��
                    safe_cells--; //�ش� ���� �������밡 �ְ� (r,c)�� �ƴ϶��
                    if (print)cout << "�ϳ� ���� (" << cols[c] << "," << c << ")" << endl;
                    rows[cols[c]] = -1; //����
                    cols[c] = -1; //����
                }
            }
            
            if (x > save_r) {
                if (print) cout << "case 2" << endl;
                if (rows[r] != -1 && rows[r] != c) {
                    safe_cells--;
                    if (print)cout << "�ϳ� ���� (" << r << "," << rows[r] << ")" << endl;
                    cols[rows[r]] = -1; //����
                    rows[r] = -1;
                }
            }
            
            //�츮��
            if (save_r < x && save_c < x ) {// ��/������ ���� Ŀ�� ��� 
                if (save_r != save_x || save_c != save_x) {//���� �������밡 �ƴϿ��ٸ�
                    if (print) cout << "�ϳ� �߰� (" << r << "," << c << ")" << endl;
                    safe_cells++; //���� ��ġ�� �ִ� ��� ����
                    rows[r] = c;
                    cols[c] = r;
                }
            }
            if (print)cout << "safe cells: " << safe_cells << endl;
            for (int i = 0; i < N; i++) {
                if (print) printf("rows[%d]: %d\n", i, rows[i]);
            }
            sum_safe_cells += safe_cells;
        }

        cout << "#" << save - TC << " " << sum_safe_cells << endl;
    }
    return 0;
}