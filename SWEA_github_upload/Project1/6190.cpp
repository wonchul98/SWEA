#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool isIncrease(int a);

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		vector<int> v;
		int N;
		int maximum = -1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			v.push_back(input);
		}
		for (int first = 0; first < N - 1; first++) {
			for (int second = first + 1; second < N; second++) {
				if (isIncrease(v[first] * v[second])) {
					maximum = max(maximum, v[first] * v[second]);
				}
			}
		}
		cout << "#" << test_case << " " << maximum << endl;
	}
	return 0;
}

bool isIncrease(int a) {
	//cout << "a: " << a << endl;
	string num = to_string(a);
	int cur = num[0] - '0';
	for (int i = 1; i < num.length(); i++) {
		int cur_num = num[i] - '0';
		if (cur_num < cur) return false;
		cur = cur_num;
	}
	//cout << "increse " << endl;
	return true;
}