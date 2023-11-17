#include<iostream>
#include<algorithm>
#include<limits>
#include<utility>
#include<vector>
using namespace std;


int map[50][50];

int N, K;
int dp[2501][50][50];

int getMinDist(vector<vector<pair<int, int>>> v);
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		
		cin >> N >> K;
		vector<vector<pair<int, int>>> v(K+1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int input;
				cin >> input;
				map[i][j] = input;
				v[input].push_back(make_pair(i, j));
			}
		}
		for (int k = 1; k <= K; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					dp[k][i][j] = numeric_limits<int> :: max();
				}
			}
		}
		cout << "#" << test_case << " " << getMinDist(v) << endl;

	}
	return 0;
}

int getMinDist(vector<vector<pair<int, int>>> v) {
	//cout << "getMinDist()" << endl;
	if (v[1].empty()) return -1;
	for (int i = 0; i < v[1].size(); i++) {
		dp[1][v[1][i].first][v[1][i].second] = 0;
	}
	for (int num = 2; num <= K; num++) {
		//cout << "num: " << num << endl;
		if (v[num].empty()) return -1;
		for (int prevIdx = 0; prevIdx < v[num - 1].size(); prevIdx++) {
			//cout << "prevIdx: " << prevIdx << endl;
			for (int curIdx = 0; curIdx < v[num].size(); curIdx++) {
				//cout << "curIdx: " << curIdx << endl;
				int prevI = v[num - 1][prevIdx].first;
				int prevJ = v[num - 1][prevIdx].second;
				int curI = v[num][curIdx].first;
				int curJ = v[num][curIdx].second;
				int dist = abs(prevI - curI) + abs(prevJ - curJ);
				//cout << "dist: " << dist << endl;
				if (dp[num - 1][prevI][prevJ] + dist == numeric_limits<int>::max()) continue;
				dp[num][curI][curJ] = min(dp[num][curI][curJ], dp[num - 1][prevI][prevJ] + dist);
			}
		}
	}
	int ret_min = numeric_limits<int>::max();
	for (int i = 0; i < v[K].size(); i++) {
		//cout << "DP: ";
		//cout << dp[K][v[K][i].first][v[K][i].second] << endl;
		ret_min = min(ret_min, dp[K][v[K][i].first][v[K][i].second]);
	}
	return ret_min;
}