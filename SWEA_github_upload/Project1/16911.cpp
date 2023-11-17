#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>


using namespace std;
int dp[1000][1000];
int getMinCost(vector<int> v);

int N;
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {

		cin >> N;                      
		vector<int> v;
		//dp�迭�� �ʱ�ȭ����
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				dp[i][j] = numeric_limits<int>::max();
			}
		}
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			v.push_back(input);
		}
		cout << "#" << test_case << " " << getMinCost(v) << endl;
	}
	return 0;
}

int getMinCost(vector<int> v) {
	int c[1000] = { 0, };
	int colorNum = 1;
	dp[0][0] = v[0];
	c[0] = v[0];
	for (int idx = 1; idx < v.size(); idx++) {
		cout << "idx: " << idx << endl;
		int prevIdx = idx - 1;
		for (int color = 0; color < colorNum-1; color++) {
			// ������ 1 : ���� �� �� �ϳ� ����
			cout << " ---- ������ 1 ----" << endl;
			cout << "color: " << color << endl;
			for (int prevColor = 0; prevColor < colorNum; prevColor++) {
				if (prevColor == color) continue;
				cout << "prevColor: " << prevColor << endl;
				if (dp[prevIdx][prevColor] == numeric_limits<int>::max()) continue;
				printf("v[%d] : %d, c[%d]: %d\n", idx, v[idx], color, c[color]);
				if (v[idx] > c[color]) { //���� ���� �� ū������ ���� ���
					dp[idx][color] = min(dp[idx][color] , dp[prevIdx][prevColor] + v[idx] - c[color]);
					c[color] = v[idx]; //�ش� color�� �ִ밪 ����
				}
				else dp[idx][color] = min(dp[idx][color], dp[prevIdx][prevColor]);
				printf("dp[%d][%d]: %d\n", idx, color, dp[idx][color]);
			}
		}
		// ������ 2 : ���ο� ��
		cout << " ---- ������ 2 ----" << endl;
		int newColor = colorNum;
		dp[idx][newColor] = numeric_limits<int>::max();
		for (int i = 0; i < colorNum; i++) {
			if (dp[prevIdx][i] == numeric_limits<int>::max()) continue;
			cout << dp[prevIdx][i] << endl;
			dp[idx][newColor] = min(dp[idx][newColor], dp[prevIdx][i] + v[idx]);
		}
		printf("dp[%d][%d]: %d\n", idx, newColor, dp[idx][newColor]);
		c[newColor] = v[idx];
		colorNum++;
	}

	int minimum = numeric_limits<int>::max();
	for (int i = 0; i < colorNum; i++) {
		minimum = min(minimum, dp[N - 1][i]);
	}
	return minimum;
}