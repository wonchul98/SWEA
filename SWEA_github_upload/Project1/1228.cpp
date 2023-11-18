#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	int T = 10;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N;
		cin >> N;
		vector<int> v;
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			v.push_back(input);
		}
		int c;
		cin >> c; //¸í·É¾î °¹¼ö
		for (int i = 0; i < c; i++) {
			char I;
			int loc, num, insert_num;
			cin >> I;
			cin >> loc >> num;
			for (int j = 0; j < num; j++) {
				cin >> insert_num;
				v.insert(v.begin() + loc + j, insert_num);
			}
			
		}
		string rst;
		for (int i = 0; i < 10; i++) {
			rst += to_string(v[i]);
			rst += ' ';
		}
		rst[rst.length()] = '0';
		cout << "#" << test_case << " " << rst << endl;
	}
	return 0;
}