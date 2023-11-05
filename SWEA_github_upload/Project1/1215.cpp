#include<iostream>

using namespace std;

int map[8][8];

int search(int x, int y, int n);
bool search_right(int x, int y, int n);
bool search_down(int x, int y, int n);


int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		
		int N;
		cin >> N;
		for (int i = 0; i < 8; i++) {
			string input;
			cin >> input;
			for (int j = 0; j < 8; j++) {
				map[i][j] = input[j];
			}
		}
		int num = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				num += search(i, j, N);
			}
		}
		cout << "#" << test_case << " " << num << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int search(int x, int y, int n) {
	//cout << "search" << x << " " << y << endl;
	int rst = 0;
	if (y + n - 1 < 8) {
		if (search_right(x, y, n)) rst++;
	}
	if (x + n - 1 < 8) {
		if (search_down(x, y, n)) rst++;
	}
	
	return rst;
}

bool search_down(int x, int y, int n) {
	for (int i = 0; i < n / 2; i++) {
		if (map[x + i][y] != map[x + n - 1 - i][y]) return false;
	}
	//cout << "down in " << x << y << endl;
	return true;
}

bool search_right(int x, int y, int n) {
	for (int i = 0; i < n / 2; i++) {
		if (map[x][y+i] != map[x][y + n - 1 - i]) return false;
	}
	//cout << "right in " << x << y << endl;
	return true;
}