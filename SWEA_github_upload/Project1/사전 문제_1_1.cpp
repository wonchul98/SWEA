#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input/사전문제1_input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
\

        for (int i = 0; i < M; i++) {
            int X, Y, C;
            cin >> X >> Y >> C;
            dist[X][Y] = C;
        }

        int smallest_cycle = INF;
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            smallest_cycle = min(smallest_cycle, dist[i][i]);
        }

        cout << "#" << tc << " " << (smallest_cycle == INF ? -1 : smallest_cycle) << endl;
    }
    return 0;
}