#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int dp[1005][1005] = { 0, };

int main() {
	freopen("input.txt", "r", stdin);
	int testcase;
	cin >> testcase;
	string src, dest;
	for (int i = 1; i <= testcase; i++) {
		cin >> src >> dest;
		for (int i = 0; i <= src.length(); i++) {
			for (int j = 0; j <= dest.length(); j++) {
				if (i == 0 || j == 0) dp[i][j] = 0;
				else if (src[i - 1] == dest[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << "#" << i << " " << dp[src.length()][dest.length()] << endl;
		for (int j = 0; j <= src.length(); j++) {
			for (int k = 0; k <= dest.length(); k++) {
				dp[j][k] = 0;
			}
		}
	}

	return 0;
}
