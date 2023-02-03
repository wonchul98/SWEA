#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cassert>

using namespace std;

int play(int a, int i, int j, int take);

int N, M;
int A[3002];
int B[102];
int dp[3002][102][102][2];

int main() {
	freopen("input/8935_input.txt", "r", stdin);
	int testcase;
	cin >> testcase;
	for (int j = 0; j < testcase; j++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}
		sort(B, B + 101, greater<int>());
		memset(dp, -1, sizeof(dp));
		cout << "#" << j+1 << " "<<play(0, 0, 0, 0) << endl;
	}
	return 0;
}

int play(int a, int i, int j, int take) {
	//printf("a: %d, i: %d, j: %d, take: %d\n", a, i, j, take);
	if (dp[a][i][j][take] != -1) return dp[a][i][j][take]; //�̹� �Դ� �� �̶��
	int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
	if (take) {//�� ���� �������ٸ�
		if(a<N) val1 = play(a + 1, i, j, 0);//a�� ����
		if (i+j<M)val2 = play(a, i, j + 1, 0);//b�� ����
	}
	else {//�� ���� �Ȱ��� ���ٸ�
		if (a < N) {
			val1 = play(a + 1, i, j, 0); //�̹����� a����
			val2 = play(a + 1, i, j, 1) + A[a]; //�̹����� a������
		}
		if (i + j < M) {
			val3 = play(a, i, j + 1, 0);//�̹����� b����
			val4 = play(a, i + 1, j, 1) + B[i];//�̹����� b������
		}
	}
	//printf("dp[%d][%d][%d][%d] = %d\n", a, i, j, take, max(val1, max(val2, max(val3, val4))));
	return dp[a][i][j][take] = max(val1, max(val2, max(val3, val4)));
}