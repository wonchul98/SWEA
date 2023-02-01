#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321
#include<iostream>
#include<algorithm>
#include<cassert>
#include<queue>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int N;

int map[100][100];
int visited[100][100] = { 0, };
int cost[100][100] = { 0, };
int solve();
void init();
queue<pair<int, int>> Q;

int main() {
	freopen("input/1249_input.txt", "r", stdin);
	int testcase;
	cin >> testcase;
	for (int C = 1; C <= testcase; C++) {
		cin >> N;
		init();
		string input;
		for (int i = 0; i < N; i++) {
			cin >> input;
			for (int j = 0; j < N; j++) {
				map[i][j] = input[j] - '0';
			}
		}
		cout << "#" << C <<" " <<solve() << endl;
	}
	return 0;
}

int solve() {
	int idx_x = 0, idx_y = 0;
	Q.push(make_pair(0, 0));
	while (!Q.empty()) {
		idx_x = Q.front().first;
		idx_y = Q.front().second;
		//cout << "idx_x: " << idx_x << " idx_y: " << idx_y << endl;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = idx_x + dx[i];
			int ny = idx_y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (cost[nx][ny] > cost[idx_x][idx_y] + map[nx][ny]) {
				//printf("nx: %d ny: %d\n", nx, ny);
				cost[nx][ny] = cost[idx_x][idx_y] + map[nx][ny];
				Q.push(make_pair(nx, ny));
			}
		}
	}
	return cost[N - 1][N - 1];
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
			cost[i][j] = INF;
		}
	}
	cost[0][0] = 0;
}