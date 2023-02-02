#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

char string_arr[50001] = {0,};
int t_size = 0;

void init(int N, char init_string[]);
int change(char string_A[], char string_B[]);
void result(char ret[]);
int found(char string_A[]);

int main() {
	char input[] = "hi my name is wonchul";
	init(strlen(input), input);
	for (int i = 0; i < t_size; i++) {
		cout << string_arr[i];
	}
	cout << endl;
	char input2[] = "won";
	cout << found(input2) << endl;
	char input3[] = "bbb";
	change(input2, input3);
	char* ret = new char[t_size];
	result(ret);
	for (int i = 0; i < t_size; i++) {
		cout << ret[i];
	}
	cout << endl;
	delete ret;
	return 0;
}

void init(int N, char init_string[]) {
	t_size = N;
	for (int i = 0; i < N; i++) {
		string_arr[i] = init_string[i];
	}
}

int change(char string_A[], char string_B[]) {
	int num = 0;
	while (1) {
		int idx = found(string_A);
		if (idx == -1) return -1;
		num++;
		for (int i = 0; i < 3; i++) {
			string_arr[idx++] = string_B[i];
		}
	}
	return num;
}

void result(char ret[]) {
	for (int i = 0; i < t_size; i++) {
		ret[i] = string_arr[i];
	}
}

int found(char string_A[]) {
	int p_size = strlen(string_A);
	int t_idx = 0, p_idx = 0;
	int skip[52];
	for (int i = 0; i < 52; i++) {
		skip[i] = -1;
	}
	for (int i = 0; i < p_size; i++) {
		skip[(int)string_A[i] - 'a'] = i;
	}
	bool found = true;
	while (t_idx <= t_size - p_size) {
		found = true;
		for (int p_idx = p_size - 1; p_idx >= 0;p_idx--) {
			if (string_arr[t_idx + p_idx] != string_A[p_idx]) {//다른 경우
				found = false;
				t_idx += max(1, (p_idx - skip[string_arr[t_idx + p_idx] - 'a']));
				break;
			}
			
		}
		if (p_idx == 0 && found) {
			break;
		}
	}
	if (found) return t_idx;
	else return -1;
}