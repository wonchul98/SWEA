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
			child[input].push(i); //�ڽ� ����
			depth[i] = depth[input] + 1;
			dp[i][0] = input;//0������ �θ� ����
			for (int j = 1; j < floor(log2(depth[i])) + 1; j++) {//1�� ���ʹ� dp
				dp[i][j] = dp[dp[i][j - 1]][j - 1];
				//printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
			}

		}
		printf("make dp complete!\n");
		solve();
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

void solve() {
	Q.push(1);
	int front;
	int cur;
	while (!Q.empty()) {
		front = Q.front();
		while (!child[front].empty()) { //�ڽĵ� Ǫ��
			Q.push(child[front].front());
			child[front].pop();
		}
		Q.pop();
		/*����*/
		if (Q.empty()) break;
		cur = Q.front();
		bool flag = false;

		if (depth[cur] != depth[front]) { //���� �ٸ����
			cur = parent[cur]; //���� ������
			//cout << "�� ���߱�: " << endl;
			flag = true;
		}
		//cout << "cur: " << cur << " front: " << front << endl;
		int save_cur = cur; //����
		int save_front = front;
		int moving_cur = cur;
		int moving_front = front;
		int iter = 0;
		while (cur != front) {
			if (dp[cur][iter] == dp[front][iter]) {//������ �ٸ���, �������� �������ٸ�
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

			//if (depth[save_cur] < pow(2, iter)) { iter = 0; moving_cur = cur; moving_front = front; }//���� Ž�� ������ root�� �Ѿ�� ���
		}
		//cout << "���� ����: " << cur << endl;
		if (flag) cnt += (2 * (depth[save_cur] - depth[cur])) + 1; //���� �޶��� ���
		else cnt += (2 * (depth[save_cur] - depth[cur])); // ���� ���Ҵ� ���
		//if (flag) cout << "cnt += " << (2 * (depth[save_cur] - depth[cur])) + 1 << " cnt: " << cnt << endl;
		//else cout << "cnt += " << (2 * (depth[save_cur] - depth[cur])) << " cnt: " << cnt << endl;
	}
}