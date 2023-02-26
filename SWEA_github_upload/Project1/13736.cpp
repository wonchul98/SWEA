#define _CRT_SECURE_NO_WARNINGS	
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long T, A, B, k;

long long power(long long a, long long b, long long hap);

int main() {
	freopen("input/13736_input.txt", "r", stdin);
	cin >> T;

	for (int i = 1; i <= T; i++) {
		cin >> A >> B >> k;
		long long X, Y;
		X = min(A, B);
		long long hap = A + B;
		long long ret = (power(2, k, hap) * X)%hap;
		ret = min(ret, hap - ret);
		cout << "#" << i << " " << ret << endl;
	}
	return 0;
}

long long power(long long a, long long b, long long hap) {
	long long mid = b / 2; 
	if (b==1) return a;
	long long res;
	res = power(a, mid, hap);
	res = res * res % hap;
	if (b % 2 != 0) return (res * a)%hap;
	else return res % hap;
}