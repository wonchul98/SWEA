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
	freopen("input/��������1_input.txt", "r", stdin);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cur_cost = 0; min_cost = 987654321, until = 0;
		for (int j = 1; j <= N; j++) { //dist �迭 �ʱ�ȭ
			for (int k = 1; k <= N; k++) {
				dist[j][k] = 0;
			}
		}
		for (int j = 1; j <= N; j++) { //in_dfs, visited�迭 �ʱ�ȭ
			in_dfs[j] = 0;
			visited[j] = false;
		}
		for (int j = 0; j < M; j++) {
			int left, right, cost;
			cin >> left >> right >> cost;
			dist[left][right] = cost;
		}
		for (int j = 1; j <= N; j++) {//��� ��忡 ���ؼ� DFS����
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
		if (dist[cur][next] != 0) {//��ΰ� �ִ� ������ ������.
			if (print)cout << "next: " << next << "(cur: " << cur <<")" << endl;
			
			if (in_dfs[next] == 0) { // �� ���� ó�� ���� ���̸�
				in_dfs[next] = in_dfs[cur] + dist[cur][next];
				if (print)printf("in_dfs[%d]:%d\n", next, in_dfs[next]);
				DFS(next);
				in_dfs[next] = 0;
				if (print)printf("in_dfs[%d]:%d\n", next, in_dfs[next]);
			}
		    else { //�� ���� �̹� ������ ��(����)
				if(print) cout << "���� �߰�" << endl;
				cur_cost = in_dfs[cur] + dist[cur][next] - in_dfs[next];
				if (print)cout << "cur_cost: " << cur_cost << endl;
				min_cost = min(min_cost, cur_cost);
				if (print)cout << "���� min_cost: " << min_cost << endl;
				cur_cost = 0;
				//return true;
			}
			
		}
	}
	//cur���� ��� next�� ���� ���� �Ϸ�
	//visited[cur] = true;
	//if (print)cout << "visited: " << cur << endl;
	//�� ���°ų�, ���� ���� ����
	if (print) cout << "min: " << min_cost << " cur: " << cur_cost << endl;
	cur_cost = 0;
	return false;
}