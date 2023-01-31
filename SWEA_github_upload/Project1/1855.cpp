#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int parent[100002];
int depth[100002];
int dp[100002][16];
int N;
long long cnt = 0;
queue<int> child[100002];
queue<int> Q;


void solve();

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input2.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";
		cin >> N;
		int input;
		depth[1] = 0;
		for (int i = 2; i <= N; i++) {
			cin >> input;
			parent[i] = input;
			child[input].push(i); //자식 저장
			depth[i] = depth[input] + 1;
			dp[i][0] = input;//0번에는 부모 저장
			for (int j = 1; j < floor(log2(depth[i])) + 1; j++) {//1번 부터는 dp
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
				//printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
			}

		}
		printf("make dp complete!\n");
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
		bool flag = false;

		if (depth[cur] != depth[front]) { //층이 다른경우
			cur = parent[cur]; //층을 맞춰줌
			//cout << "층 맞추기: " << endl;
			flag = true;
		}
		//cout << "cur: " << cur << " front: " << front << endl;
		int save_cur = cur; //저장
		int save_front = front;
		int moving_cur = cur;
		int moving_front = front;
		int iter = 0;
		while (cur != front) {
			if (dp[cur][iter] == dp[front][iter]) {//지금은 다른데, 다음번에 같아진다면
				moving_front = front;
				moving_cur = cur;
				//printf("same next! moving_front: %d, moving_cur: %d\n", moving_front, moving_cur);
				iter = 0;
			}

			//if (depth[save_cur] < pow(2, iter)) { iter = 0; moving_cur = cur; moving_front = front; }
			cur = dp[moving_cur][iter];
			front = dp[moving_front][iter];
			//printf("iter: %d, cur: %d, front: %d\n", iter, cur, front);
			iter++;

			//if (depth[save_cur] < pow(2, iter)) { iter = 0; moving_cur = cur; moving_front = front; }//다음 탐색 범위가 root를 넘어가는 경우
		}
		//cout << "공통 조상: " << cur << endl;
		if (flag) cnt += (2 * (depth[save_cur] - depth[cur])) + 1; //층이 달랐던 경우
		else cnt += (2 * (depth[save_cur] - depth[cur])); // 층이 같았던 경우
		//if (flag) cout << "cnt += " << (2 * (depth[save_cur] - depth[cur])) + 1 << " cnt: " << cnt << endl;
		//else cout << "cnt += " << (2 * (depth[save_cur] - depth[cur])) << " cnt: " << cnt << endl;
	}
}