#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

#define MAXM 400
char str[MAXM];

class TrieNode {
public:
	int cnt;
	bool end;
	TrieNode* next[26];

	TrieNode* Alloc() {
		cnt = 0;
		end = false;
		memset(next, NULL, sizeof(TrieNode) * 26);
		return this;
	}
}
nodes[MAXM * MAXM];
int nodeCnt;
TrieNode head;

void Init() {
	nodeCnt = 0;
	head.Alloc();
}

void Add(char* s) {
	int pivot = 0;
	TrieNode* node = &head;
	while (s[pivot]) {
		int alpn = s[pivot] - 'a';
		if (!node->next[alpn]) {
			node->next[alpn] = nodes[nodeCnt++].Alloc();
		}
	}
}



int main() {

	return 0;
}

