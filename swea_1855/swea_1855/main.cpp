#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>

using namespace std;

int parent[100001];
int depth[100001];
int N;
long long cnt = 0;
queue<int> child[100001];
queue<int> Q;

void solve();

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case<<" ";
		cin >> N;
		int input;
		depth[1] = 0;
		for (int i = 2; i <= N; i++) {
			cin >> input;
			parent[i] = input;
			child[input].push(i);
			depth[i] = depth[input] + 1;
		}
		solve();
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void solve() {
	Q.push(1);
	int front;
	int cur;
	while (!Q.empty()) {
		front = Q.front();
		while (!child[front].empty()) { //자식들 푸쉬
			Q.push(child[front].front());
			child[front].pop();
		}
		Q.pop();
		/*연산*/
		if (Q.empty()) break;
		cur = Q.front();
		if (depth[cur] != depth[front]) { //층이 다른경우
			int save_cur = cur;
			while (parent[cur] != front) {
				cur = parent[cur];
				front = parent[front];
			}
			cnt += (2 * (depth[save_cur] - depth[cur])) + 1;
		}
		else {//층이 같은 경우
			int save_cur = cur;
			while (cur != front) {
				cur = parent[cur];
				front = parent[front];
			}
			cnt += 2 * (depth[save_cur] - depth[cur]);
		}
	}
	
}