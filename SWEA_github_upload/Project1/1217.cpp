#include<iostream>
using namespace std;

int recur(int a, int b, int c);
int main() {
	for (int test_case = 1; test_case <= 10; test_case++) {
		int a,b,k;
		cin >> k;
		cin >> a >> b;
		cout << "#" << test_case << " " << recur(a, b, 1) << endl;
	}
	return 0;
}

int recur(int a, int b, int c) {
	//printf("recur(%d, %d)\n", a, b);
	if (b == 0) return c;
	return recur(a, b - 1, a * c);
}