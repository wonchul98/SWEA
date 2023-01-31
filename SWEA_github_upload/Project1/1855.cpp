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
			child[input].push(i);
			depth[i] = depth[input] + 1;
			dp[i][0] = input;//0번에는 부모 저장
			for (int j = 1; j < floor(log2(depth[i])) + 1; j++) {//1번 부터는 dp
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
			}
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
		bool flag = false;
		//cout << "cur: " << cur << " front: " << front << endl;
		if (depth[cur] != depth[front]) { //층이 다른경우
			cur = parent[cur]; //층을 맞춰줌
			flag = true;
		}
		int save_cur = cur; //저장
		int save_front = front;
		int iter = 0;
		while (cur != front) {
			cur = dp[save_cur][iter];
			front = dp[save_front][iter];
			//cout << "cur: " << cur << " front: " << front << " iter: " << iter << endl;
			iter += 1;
			if (cur == front && pow(2, iter - 1) <= depth[cur]) {
				if (iter == 1) break;
				cur = dp[cur][iter - 1];
				front = dp[front][iter - 1];
				iter = 0;
			}
		}
		//cout << "공통 조상: " << cur << endl;
		if (flag) cnt += (2 * (depth[save_cur] - depth[cur])) + 1;
		else cnt += (2 * (depth[save_cur] - depth[cur]));
		//cout << "cnt += " << (2 * (depth[save_cur] - depth[cur])) + 1 << " cnt: " << cnt << endl;
	}
}