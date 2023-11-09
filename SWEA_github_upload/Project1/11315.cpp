#include<iostream>
#include<vector>
using namespace std;
int N;
char map[20][20];

bool checkRow(int i, int j);
bool checkCol(int i, int j);
bool checkDiagonal1(int i, int j);
bool checkDiagonal2(int i, int j);

int main() {
	int T;
	cin >> T;
	
	
	
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			string input;
			cin >> input;
			for (int j = 0; j < N; j++) {
				map[i][j] = input[j];
			}
		}
		bool flag;
		for (int i = 0; i < N; i++) {
			flag = false;
			for (int j = 0; j < N; j++) {
				if (j + 4 < N && checkRow(i, j)) {
					cout <<  "#" << test_case << " YES" << endl;
					flag = true;
					break;
				}
				if (i + 4 < N && checkCol(i, j)) {
					cout << "#" << test_case << " YES" << endl;
					flag = true;
					break;
				}
				if (i + 4 < N && j + 4 < N && checkDiagonal1(i, j)) {
					cout << "#" << test_case << " YES" << endl;
					flag = true;
					break;
				}
				if (i + 4 < N && j >= 4 &&checkDiagonal2(i, j)) {
					cout << "#" << test_case << " YES" << endl;
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if(!flag) cout << "#" << test_case << " NO" << endl;
	}
	return 0;
}

bool checkRow(int i, int j) {
	for (int k = 0; k < 5; k++) {
		if (map[i][j + k] == '.') return false;
	}
	//cout << "True in 1: " << i << " " << j << endl;
	return true;
}

bool checkCol(int i, int j) {
	for (int k = 0; k < 5; k++) {
		if (map[i+k][j] == '.') return false;
	}
	//cout << "True in 2: " << i << " " << j << endl;
	return true;
}

bool checkDiagonal1(int i, int j) {
	for (int k = 0; k < 5; k++) {
		if (map[i+k][j + k] == '.') return false;
	}
	//cout << "True in 3: " << i << " " << j << endl;
	return true;
}

bool checkDiagonal2(int i, int j) {
	for (int k = 0; k < 5; k++) {
		if (map[i + k][j - k] == '.') return false;
	}
	//cout << "True in 4: " << i << " " << j << endl;
	return true;
}