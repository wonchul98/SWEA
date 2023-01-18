//ù ��° �� : ���� ��ȣ���� ���� N(2000 �� N �� 4000 �� ����)
//
//�� ��° �� : ���� ��ȣ��
//
//�� ��° �� : ��ɾ��� ����(250 �� M �� 500 �� ����)
//
//�� ��° �� : ��ɾ�

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

void get_order();
void print_pass();
vector<int> pass;

int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	for (int k = 1; k <= 10; k++) {
		cout << "#" << k << " ";
		cin >> N; //��ȣ�� ����
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;
			pass.push_back(input);
		}
		cin >> M;
		for (int j = 0; j < M; j++) {
			get_order();
		}
		//cout << "ans: ";
		print_pass();
		while (!pass.empty()) {
			pass.pop_back();
		}
		
	}
	return 0;
}

void get_order() {
	char order;
	cin >> order;
	int x = 0 , y = 0, s = 0;
	if (order == 'I') {
		cin >> x >> y; //x:��ġ s���� y��
		for (int i = 0; i < y; i++) {
			cin >> s;
			pass.insert(pass.begin() + x + i, s);
		}
	}
	else if (order == 'D') { //x��ġ y�� ����
		cin >> x >> y;
		for (int i = 0; i < y; i++) {
			pass.erase(pass.begin() + x);
		}
	}
	else if (order == 'A') { //�� �ڿ� y���� ����
		cin >> y;
		for (int i = 0; i < y; i++) {
			cin >> s;
			pass.push_back(s);
		}
	}
	else {
		//cout << "WRONG input" << endl;
	}
	return;
}

void print_pass() {
	//cout << "print" << endl;
	for (int j = 0; j < 10; j++) {
		cout << pass.at(j) << " ";
	}
	cout << endl;
}