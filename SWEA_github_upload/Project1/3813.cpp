#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;
#define INF 987654321
int T, N, K, max_num = 0, min_num = INF;
int W[200001];
int S[200001];

bool able(int upper, int start, int S_idx);
int solve();

int main() {
	freopen("input/3813_input2.txt", "r", stdin);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> K;
		//printf("M: %d, K: %d\n", N, K);
		for (int j = 1; j <= N; j++) {
			cin >> W[j];
			max_num = max(max_num, W[j]);
			min_num = min(min_num, W[j]);
		}
		for (int j = 1; j <= K; j++) {
			cin >> S[j];
		}
		cout << "#" << i << " " << solve() << endl;
	}
	
	return 0;
}

bool able(int upper, int start, int S_idx) {//start�� 1����
	//printf("upper: %d, start: %d, S_idx: %d\n", upper, start, S_idx);
	int remain = 0;
	for (int i = S_idx; i <= K; i++) {
		remain += S[i];//�־�� �� �ڸ��� ����
	}
	if (remain > N - start + 1) return false; //�� �� ä���� �ȵ�� ���°��
	bool found = false;
	int found_idx = start;
	while(!found && found_idx <= N - S[S_idx] + 1) {
		//printf("found_idx: %d\n", found_idx);
		for (int found_iter = 0; found_iter < S[S_idx]; found_iter++) {
			//printf("found_iter: %d\n", found_iter);
			if (W[found_idx + found_iter] > upper) { //upper���� �� ū ���Ұ� �ִ� ���
				//printf("����\n");
				//printf("W[%d]: %d, upper: %d\n", found_idx + found_iter, W[found_idx + found_iter], upper);
				found_idx = found_idx + found_iter + 1;
				break;
			}
			if (found_iter == S[S_idx]-1) {
				//printf("founded!\n");
				found = true;
			}
		}
		if (found) break;
	}
	if (!found) return false;
	else if (S_idx == K) return true;
	else { return able(upper, found_idx + S[S_idx], S_idx + 1); }
}

int solve() {
	bool flag = false;
	int upper = max_num;
	int save_top = max_num;
	int save_down = min_num;
	int start = 1;
	int S_idx = 1;
	while (save_top - save_down > 1) {
		//printf("//while// save_down: %d, save_top: %d\n", save_down, save_top);
		if (able(upper, start, S_idx)) {
			//printf("%d is able\n", upper);
			save_top = upper; //save_top���ٴ� �۰ų� ���ƾ� ��.
			upper = (upper + save_down) / 2;
		}
		else {
			//printf("%d is not able\n", upper);
			save_down = upper; //save_down���ٴ� Ŀ����
			upper = (upper + save_top) / 2;
		}
	}
	return save_top;
}