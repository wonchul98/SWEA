#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct childnode {
    int child;
    childnode* nextptr;
};

struct Node {
    int parent;
    int depth;
    childnode* child;
};

int idx;
Node node[100002];
int queue[100000];
int dp[100002][14];      // dp[a][b]   a노드의 2^(b)번째 조상

childnode mallocnode[100002];
int idx2;

childnode* newnode(int idx) {
    mallocnode[idx2].child = idx;
    mallocnode[idx2].nextptr = nullptr;
    return &mallocnode[idx2++];
}

int log2(int N) {
    int ret = 0;
    while (N) {
        N /= 2;
        ret++;
    }
    return ret - 1;
}

int main() {
    int test_case;
    int T;
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        idx2 = 0;
        int N;
        scanf("%d", &N);
        idx = 1;
        node[idx].parent = 0;
        node[idx].depth = 1;
        node[idx].child = nullptr;
        memset(dp, 0, sizeof(int) * 100002);
        dp[1][0] = 1;

        for (int i = 2; i < N + 1; i++) {
            int parent_idx, cur_depth;
            scanf("%d", &parent_idx);
            node[i].parent = parent_idx;
            cur_depth = node[parent_idx].depth + 1;
            node[i].depth = cur_depth;
            node[i].child = nullptr;
            if (node[parent_idx].child == nullptr) {
                node[parent_idx].child = newnode(i);
            }
            else {
                childnode* head = node[parent_idx].child;
                while (head->nextptr != nullptr)
                    head = head->nextptr;
                head->nextptr = newnode(i);
            }
            int dp_idx = 0;
            dp[i][dp_idx++] = parent_idx;
            int loop = log2(cur_depth - 1);
            for (int j = 0; j < loop; j++) {
                dp[i][dp_idx] = dp[parent_idx][dp_idx - 1];
                parent_idx = dp[i][dp_idx++];
            }
        }

        int front = 0, rear = 0;
        int distance = 0;
        int cur_idx = 1;

        queue[front++] = 1;
        while (front != rear) {
            int next_idx = queue[rear];
            rear = (rear + 1) % 10000;
            childnode* tempnode = node[next_idx].child;
            while (tempnode != nullptr) {
                queue[front] = tempnode->child;
                front = (front + 1) % 10000;
                tempnode = tempnode->nextptr;
            }

            int cur_depth = node[cur_idx].depth;
            int next_depth = node[next_idx].depth;
            int next_idx_tmp = next_idx;
            int cur_idx_tmp = cur_idx;
            int max_level = 13;
            if (cur_depth != next_depth) {      // cur_idx <= next_idx
                for (int i = max_level; i >= 0; i--) {
                    if (node[cur_idx_tmp].depth <= node[dp[next_idx_tmp][i]].depth)
                        next_idx_tmp = dp[next_idx_tmp][i];
                }
            }
            int lca = cur_idx_tmp;
            if (cur_idx_tmp != next_idx_tmp) {
                for (int i = max_level; i >= 0; i--) {
                    if (dp[cur_idx_tmp][i] != dp[next_idx_tmp][i]) {
                        cur_idx_tmp = dp[cur_idx_tmp][i];
                        next_idx_tmp = dp[next_idx_tmp][i];
                    }
                    lca = dp[cur_idx_tmp][i];
                }
            }
            distance += node[cur_idx].depth + node[next_idx].depth - 2 * node[lca].depth;

            cur_idx = next_idx;
        }
        printf("#%d %d\n", test_case, distance);
    }
    return 0;
}