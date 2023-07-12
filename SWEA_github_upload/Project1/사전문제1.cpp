#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int T, M, N;
int cur_cost = 0, min_cost = 987654321;
int until;
bool visited[401];
int in_dfs[401];
int dist[401][401] = { 0, };
bool DFS(int cur);

bool print = false;
int main() {
	freopen("input/사전문제1_input.txt", "r", stdin);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cur_cost = 0; min_cost = 987654321, until = 0;
		for (int j = 1; j <= N; j++) { //dist 배열 초기화
			for (int k = 1; k <= N; k++) {
				dist[j][k] = 0;
			}
		}
		for (int j = 1; j <= N; j++) { //in_dfs, visited배열 초기화
			in_dfs[j] = 0;
			visited[j] = false;
		}
		for (int j = 0; j < M; j++) {
			int left, right, cost;
			cin >> left >> right >> cost;
			dist[left][right] = cost;
		}
		for (int j = 1; j <= N; j++) {//모든 노드에 대해서 DFS수행
			if(!visited[j]) DFS(j);
		}
		printf("#%d %d\n", i + 1, min_cost);
	}
	return 0;
}

bool DFS(int cur) {
	//if (visited[cur]) return false;
	if(print) printf("DFS(%d)\n", cur);
	for (int next = 1; next <= N; next++) {
		if (dist[cur][next] != 0) {//경로가 있는 곳으로 보낸다.
			if (print)cout << "next: " << next << "(cur: " << cur <<")" << endl;
			
			if (in_dfs[next] == 0) { // 갈 곳이 처음 가는 곳이면
				in_dfs[next] = in_dfs[cur] + dist[cur][next];
				if (print)printf("in_dfs[%d]:%d\n", next, in_dfs[next]);
				DFS(next);
				in_dfs[next] = 0;
				if (print)printf("in_dfs[%d]:%d\n", next, in_dfs[next]);
			}
		    else { //갈 곳이 이미 지났던 곳(루프)
				if(print) cout << "루프 발견" << endl;
				cur_cost = in_dfs[cur] + dist[cur][next] - in_dfs[next];
				if (print)cout << "cur_cost: " << cur_cost << endl;
				min_cost = min(min_cost, cur_cost);
				if (print)cout << "갱신 min_cost: " << min_cost << endl;
				cur_cost = 0;
				//return true;
			}
			
		}
	}
	//cur에서 모든 next에 대한 검증 완료
	//visited[cur] = true;
	//if (print)cout << "visited: " << cur << endl;
	//다 보냈거나, 보낼 곳이 없다
	if (print) cout << "min: " << min_cost << " cur: " << cur_cost << endl;
	cur_cost = 0;
	return false;
}