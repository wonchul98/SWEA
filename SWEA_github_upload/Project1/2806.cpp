#include<iostream>
#include<vector>
#include<utility>
using namespace std;

bool map[10][10] = { 0, };
bool visited[10][10] = { 0, };
int N, cnt;
bool print = false;
vector<pair<int,int>> v[10][10];
void clear_map() {
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = false;
			visited[i][j] = false;
		}
	}
}
void check_map(int a, int b) {
	if (print) printf("check_map(%d, %d)\n", a, b);
	for (int i = 0; i < N; i++) {
		if (!map[a][i]) {
			if (print)cout << "check: " << a << " " << i << endl;
			v[a][b].push_back(make_pair(a, i));
			map[a][i] = true;
		}
		if (!map[i][b]) {
			if (print)cout << "check: " << i << " " << b << endl;
			map[i][b] = true;
			v[a][b].push_back(make_pair(i, b));
		}
		if (i < N && i + b - a < N && i + b - a >= 0 && !map[i][i + b - a]) {
			if (print)cout << "check: " << i << " " << i + b - a << endl;
			map[i][i + b - a] = true;
			v[a][b].push_back(make_pair(i, i + b - a));
		}
		if (a + b - i < N && a + b - i >= 0 && !map[i][a + b - i]) {
			if (print)cout << "check: " << i << " " << a + b - i << endl;
			map[i][a + b - i] = true;
			v[a][b].push_back(make_pair(i, a + b - i));
		}
		
	}
}

void uncheck_map(int a, int b) {
	while (!v[a][b].empty()) {
		map[v[a][b][v[a][b].size() - 1].first][v[a][b][v[a][b].size() - 1].second] = false;
		v[a][b].pop_back();
	}
}
void DFS(int depth, int x) {
	if (print) printf("DFS(%d, %d)\n", depth, x);
	if (depth == N - 1) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (print)cout << "i: " << i << endl;
		if (!map[depth+1][i]) {
			check_map(depth+1, i);
			DFS(depth + 1, i);
			uncheck_map(depth + 1, i);

		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		
		cin >> N;
		clear_map();
		DFS(-1, 0);
		cout << "#" << test_case << " " << cnt << endl;

	}
	return 0;

}