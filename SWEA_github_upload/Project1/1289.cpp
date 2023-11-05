#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;
		int cur_num = 0;
		int num = 0;
		for (int j = 0; j < input.length(); j++) {
			if (input[j] - '0' != cur_num) {
				if (cur_num == 1) cur_num = 0;
				else cur_num = 1;
				num++;
			}
		}
		cout << "#" << i << " " << num << endl;
	}
	return 0;
}