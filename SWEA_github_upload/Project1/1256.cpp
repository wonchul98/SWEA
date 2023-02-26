#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int T;
constexpr char OFFSET = 'a';

int main() {
	freopen("input/1256_input.txt", "r", stdin);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int order[27];
		char sorted[401];
		memset(order, 0, sizeof(order));
		int K;
		cin >> K;
		cout << "K: " << K << endl;
		string input;
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			order[input[j] - OFFSET]++;
		}
		int cnt = 1;
		for (int j = 0; j < 26; j++) {
			if (order[j] > 0) {
				for (int k = 0; k < order[j]; k++) {
					sorted[cnt] = j + OFFSET;
					printf("sorted[%d]: %c\n", cnt, j + OFFSET);
					cnt++;
				}
			}
		}

	}
	return 0;
}