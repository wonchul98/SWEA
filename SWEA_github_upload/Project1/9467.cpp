#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

char string_arr[50000] = {0,};
int t_size = 0;

void init(int N, char init_string[]);
int change(char string_A[], char string_B[]);
void result(char ret[]);
int found(char string_A[]);

int main() {
	
	return 0;
}

void init(int N, char init_string[]) {
	t_size = N;
	for (int i = 0; i < N; i++) {
		string_arr[i] = init_string[i];
	}
}

int change(char string_A[], char string_B[]) {

}

int found(char string_A[]) {
	int p_size = sizeof string_A / sizeof string_A[0];
	cout << "p_size: " << p_size << endl;
	int t_idx = 0, p_idx = 0;
	int skip[52];
	for (int i = 0; i < p_size; i++) {
		skip[(int)string_A[i] - 'a'] = i;
	}
	bool found = false;
	while (t_idx < t_size - p_size) {
		for (int p_idx = p_size - 1; p_idx >= 0;p_idx--) {
			if (string_arr[t_idx + p_idx] != string_A[p_idx]) {//다른 경우
				t_idx += p_idx - skip[string_arr[t_idx + p_idx] - 'a'];
			}
			else found = true;
		}
		if (found) break;
	}
	return t_idx;
}