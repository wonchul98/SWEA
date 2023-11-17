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
		//dp배열도 초기화하자
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
			// 선택지 1 : 기존 색 중 하나 선택
			cout << " ---- 선택지 1 ----" << endl;
			cout << "color: " << color << endl;
			for (int prevColor = 0; prevColor < colorNum; prevColor++) {
				if (prevColor == color) continue;
				cout << "prevColor: " << prevColor << endl;
				if (dp[prevIdx][prevColor] == numeric_limits<int>::max()) continue;
				printf("v[%d] : %d, c[%d]: %d\n", idx, v[idx], color, c[color]);
				if (v[idx] > c[color]) { //기존 색깔에 더 큰값으로 들어가는 경우
					dp[idx][color] = min(dp[idx][color] , dp[prevIdx][prevColor] + v[idx] - c[color]);
					c[color] = v[idx]; //해당 color의 최대값 갱신
				}
				else dp[idx][color] = min(dp[idx][color], dp[prevIdx][prevColor]);
				printf("dp[%d][%d]: %d\n", idx, color, dp[idx][color]);
			}
		}
		// 선택지 2 : 새로운 색
		cout << " ---- 선택지 2 ----" << endl;
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