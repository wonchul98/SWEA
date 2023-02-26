#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <algorithm>

using namespace std;
#define INF 987654321
extern int init(int N, int sCity[], int eCity[], int mCost[]);
extern void add(int sCity, int eCity, int mCost);
extern int dijks(int mHub);
extern int dijks2(int mHub);
extern int cost(int mHub);
extern int getsmallindex(int a);
extern int getsmallindex2(int a);

int visitedarr[1401];
int v[601][601] = { 0, };
int v2[601][601] = { 0, };
int costarr[601][601]; 
int costarr2[601][601];
int dijk[601][601];
int dijk2[601][601];
int all;
bool flag = false;

int visited(int N, int a) {
    //printf("visited(%d,%d)\n", N, a);
    for (int i = 1; i <= N; i++) {
        if (visitedarr[i] == a) return i;
    }
    
    return 0;
}

int init(int N, int sCity[], int eCity[], int mCost[]) {
    visitedarr[0] = 0;
    for (int i = 1; i <= 600; i++) {
        visitedarr[i] = 0;
        for (int j = 1; j <= 600; j++) {
            costarr2[i][j] = INF;
            costarr[i][j] = INF;
            dijk[i][j] = INF;
            dijk2[i][j] = INF;
            v[i][j] = 0;
            v2[i][j] = 0;
        }
    }
    int cnt = 1;
    int start, end;
    for (int i = 0; i < N; i++) {
        start = visited(cnt, sCity[i]); //도시번호를 index로 변환
        end = visited(cnt, eCity[i]);
        if (!start) { //처음 방문하는 곳
            visitedarr[cnt] = sCity[i];
            start = cnt++;
        }

        if (!end) { // 처음 방문하는 곳
            visitedarr[cnt] = eCity[i];
            end = cnt++;
        }
        costarr[start][end] = mCost[i];
        costarr2[end][start] = mCost[i];
        //printf("costarr[%d][%d] : %d\n", start, end, mCost[i]);
    }
    all = cnt - 1;
    for (int i = 1; i <= all; i++) {
        costarr[i][i] = 0;
        costarr2[i][i] = 0;
    }
    return cnt - 1;
}

void add(int sCity, int eCity, int mCost) {
    //printf("add: %d, %d, %d\n", sCity, eCity, mCost);
    for (int i = 1; i <= all; i++) {
        for (int j = 1; j <= all; j++) {
            v[i][j] = 0;
            v2[i][j] = 0;
        }
    }
    int start = visited(all, sCity);
    int end = visited(all, eCity);
    costarr[start][end] = mCost;
    costarr2[end][start] = mCost;
}

int dijks(int mHub) {
    //printf("dijks1, mHub: %d ", mHub);
    int costidx = visited(all, mHub);
    //printf("costidx: %d\n", costidx);
    for (int i = 1; i <= all; i++) {
        dijk[costidx][i] = costarr[costidx][i]; //시작점 기준 dijk초기화
        //printf("dijk[%d][%d]: %d\n",costidx, i, dijk[costidx][i]);
    }
    while (1) {
        int idx = getsmallindex(costidx);//가장 가까운 노드
        //printf("nearest idx: %d\n", idx);
        if (!idx) break;
        for (int i = 1; i <= all; i++) {
            dijk[costidx][i] = min(dijk[costidx][idx] + costarr[idx][i], dijk[costidx][i]);
        }
    }
    int ret = 0;
    for (int i = 1; i <= all; i++) {
        //printf("dijk[%d][%d]: %d\n", costidx, i, dijk[costidx][i]);
        ret += dijk[costidx][i];
    }
    //printf("return dijks: %d\n", ret);
    return ret;
}

int dijks2(int mHub) {
    //printf("dijks2, mHub: %d ", mHub);
    int costidx = visited(all, mHub);
    //printf("costidx: %d\n", costidx);
    for (int i = 1; i <= all; i++) {
        dijk2[costidx][i] = costarr2[costidx][i]; //시작점 기준 dijk초기화
        //printf("%d %d\n", i, costarr[costidx][i]);
    }
    while (1) {
        int idx = getsmallindex2(costidx);//가장 가까운 노드
        //printf("nearest idx: %d\n", idx);
        if (!idx) break;
        for (int i = 1; i <= all; i++) {
            dijk2[costidx][i] = min(dijk2[costidx][idx] + costarr2[idx][i], dijk2[costidx][i]);
        }
    }
    int ret = 0;
    for (int i = 1; i <= all; i++) {
        //printf("dijk[%d][%d]: %d\n", costidx, i, dijk[costidx][i]);
        ret += dijk2[costidx][i];
    }
    //printf("return dijks2: %d\n", ret);
    return ret;
}

int cost(int mHub) {
    int cnt = 0;
    cnt += dijks(mHub);
    cnt += dijks2(mHub);
    //printf("/////////////cnt: %d/////////\n", cnt);
    return cnt;
}


int getsmallindex(int a) {
    int minimum = INF;
    int idx = 0;
    for (int i = 1; i <= all; i++) {
        //printf("v[%d][%d]: %d\n", a, i, v[a][i]);
        if (!v[a][i] && minimum > dijk[a][i]) {
            minimum = dijk[a][i];
            idx = i;
        }
    }
    v[a][idx] = 1;
    return idx;
}

int getsmallindex2(int a) {
    int minimum = INF;
    int idx = 0;
    for (int i = 1; i <= all; i++) {
        //printf("v[%d][%d]: %d\n", a, i, v[a][i]);
        if (!v2[a][i] && minimum > dijk2[a][i]) {
            minimum = dijk2[a][i];
            idx = i;
        }
    }
    v2[a][idx] = 1;
    return idx;
}

//int main() {
//    int sCity[10] = { 3,1,5,5,3,5,1,4,2,4 };
//    int eCity[10] = { 2,4,3,4,5,2,5,1,3,5 };
//    int mCost[10] = { 46,15,30,31,23,47,35,24,32,13 };
//    printf("init: %d\n", init(10, sCity, eCity, mCost));
//    //printf("dijks: %d\n", dijks(5));
//    printf("cost: %d\n", cost(5));
//    return 0;
//}


/////////////////////////////////////////////////////////////////////////

#define MAX_N 1400
#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_COST 3

static bool run() {
    int q;
    scanf("%d", &q);

    int n;
    int sCityArr[MAX_N], eCityArr[MAX_N], mCostArr[MAX_N];
    int sCity, eCity, mCost, mHub;
    int cmd, ans, ret = 0;
    bool okay = false;

    for (int i = 0; i < q; ++i) {
        scanf("%d", &cmd);
        switch (cmd) {
        case CMD_INIT:
            okay = true;
            scanf("%d", &n);
            for (int j = 0; j < n; ++j) {
                scanf("%d %d %d", &sCityArr[j], &eCityArr[j], &mCostArr[j]);
            }
            scanf("%d", &ans);
            ret = init(n, sCityArr, eCityArr, mCostArr);
            if (ans != ret) {
                printf("ans: %d\n", ans);
                okay = false;
            }
            break;
        case CMD_ADD:
            scanf("%d %d %d", &sCity, &eCity, &mCost);
            add(sCity, eCity, mCost);
            break;
        case CMD_COST:
            scanf("%d %d", &mHub, &ans);
            ret = cost(mHub);
            if (ans != ret) {
                printf("ans: %d\n", ans);
                okay = false;
            }
            break;
        default:
            okay = false;
            break;
        }
    }
    return okay;
}

int main() {
    setbuf(stdout, NULL);
    freopen("input/HUB_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++) {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}