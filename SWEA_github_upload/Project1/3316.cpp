#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<bitset>

using namespace std;

long long save[2][8];
void solve();
bitset<4> make_bin(int a, int b);
vector<bitset<4>> not_bin(bitset<4> bin, int b);
string text;
void recur(vector<bitset<4>> before, vector<bitset<4>> cur, int cnt);

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		for (int j = 0; j < 8; j++) {
			save[0][j] = 1;
		}
		long long rst = 0;
		cin >> text;
		//cout << "size: " << text.size() << endl;
		if (text.at(0) == 'A') recur(not_bin(make_bin(0, 4), 8), not_bin(make_bin(1, 8), 8), 0);
		else recur(not_bin(make_bin(0, 4), 4), not_bin(make_bin(1, 8), 8), 0);
		vector<bitset<4>> before = not_bin(make_bin(1, 8), 8);
		for (int j = 0; j + 1 < text.size() - 1; j++) {
			vector<bitset<4>> cur = not_bin(make_bin(j + 2, 8), 8);
			recur(before, cur, j + 1);
			before = cur;
		}

		for (int j = 0; j < 8; j++) {
			rst += save[1][j];
			rst %= 1000000007;
		}

		cout << "#" << i << " " << rst << endl;
	}
	return 0;
}

bitset<4> make_bin(int a, int b) {//문자열의 a번째 문자를 사용하여 비트 생성
	//printf("make_bin(%d,%d)\n", a, b);
	char C = text.at(a);
	if (b == 4) {
		//cout << text[a] << endl;
		if (C == 'A') return 1; //0001
		else if (C == 'B') return 3; //0011
		else if (C == 'C') return 5; //0101
		else return 9;//1001
	}
	else {//b == 8
		if (C == 'A') return 1;//0001
		else if (C == 'B') return 2;//0010
		else if (C == 'C') return 4;//0100
		else return 8;//1000
	}

}

vector<bitset<4>> not_bin(bitset<4> bin, int b) { //2진수와 output개수를 인자로 받음
	//cout << "not_bin(" << bin << "," << b << ")" << endl;
	//cout << text << endl;
	int cnt = 0;
	vector<bitset<4>> output;
	for (int i = 0; i < 16; i++) {
		if ((bin & bitset<4>(i)) == 0) { //겹치는게 없다면
			output.push_back(bin | bitset<4>(i));
			//cout << "pushed " << output.back() << endl;
			cnt++;
			if (cnt == b) return output;
		}
	}
}

void recur(vector<bitset<4>> before, vector<bitset<4>> cur, int cnt) {
	//printf("recur(cnt: %d)\n", cnt);
	//cout << text << endl;
	if (cnt != 0) {
		for (int i = 0; i < 8; i++) {
			save[0][i] = save[1][i];
		}
	}
	int n;
	if (cnt == 0 && text.at(0) != 'A') n = 4;
	else n = 8;
	for (int i = 0; i < 8; i++) {
		long long rst = 0;
		for (int j = 0; j < n; j++) {
			if ((before.at(j) & cur.at(i)) != 0) { //겹치는게 있다.
				rst += save[0][j];
			}
		}
		save[1][i] = rst % 1000000007; //결과 저장
		//printf("save[%d][%d]: %lld\n", 1, i, save[1][i]);
	}

	//if (cnt + 1 < text.size() - 1) {
	//	//cout << "cnt: " << cnt << endl;
	//	recur(cur, not_bin(make_bin(cnt + 2, 8), 8), cnt + 1);
	//}
}