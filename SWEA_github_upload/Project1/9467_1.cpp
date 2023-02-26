#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

char string_arr[50001] = { 0, };
int t_size = 0;

void init(int N, char init_string[]);
int change(char string_A[], char string_B[]);
void result(char ret[]);
int found(int idx, char string_A[]);

extern void init(int n, char init_string[]);
extern int change(char string_A[], char string_B[]);
extern void result(char ret[]);

static int seed = 5;  // seed can be changed
static int pseudo_rand(void)
{
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}

#define MAXL (50005)
#define DUMMY_LEN (5959)

static int init_string_len = 0, char_type = 0, query_cnt = 0;
static char dummy1[DUMMY_LEN];
static char init_string[MAXL];
static char dummy2[DUMMY_LEN];
static char result_string[MAXL];
static char dummy3[DUMMY_LEN];
static char user_ans_string[MAXL];
static char dummy4[DUMMY_LEN];
static char string_A[4], string_B[4];


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main() {
    setbuf(stdout, NULL);
    //freopen("input/9467_input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    int total_score = 0;
    for (int TC = 1; TC <= T; TC++) {
        int score = 100;
        scanf("%d%d%d%d", &seed, &init_string_len, &char_type, &query_cnt);

        
        for (int i = 0; i < init_string_len; i++)
        {
            init_string[i] = pseudo_rand() % char_type + 'a';
        }
        init_string[init_string_len] = '\0';

        init(init_string_len, init_string);

        string_A[3] = string_B[3] = '\0';
        for (int i = 0; i < query_cnt; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                string_A[k] = pseudo_rand() % char_type + 'a';
                string_B[k] = pseudo_rand() % char_type + 'a';
            }
            int user_ans = change(string_A, string_B);
            int ans;
            scanf("%d", &ans);
            if (ans != user_ans)
            {
                score = 0;
            }
        }

        result(user_ans_string);
        
        scanf("%s", result_string);

        for (int i = 0; i < init_string_len; i++)
        {
            if (result_string[i] != user_ans_string[i])
            {
                score = 0;
                break;
            }
        }

        total_score += score;
        printf("#%d %d\n", TC, score);
    }
    printf("Total score : %d\n", total_score / T);

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
    int idx = found(0, string_A);
    //printf("idx: %d\n", idx);
    if (idx == -1) return 0;
    while (idx!=-1) {
        //printf("idx i change: %d\n", idx);
        num++;
        for (int i = 0; i < 3; i++) {
            string_arr[idx++] = string_B[i];
        }
        idx = found(idx, string_A);
    }
    //for (int i = 0; i < init_string_len; i++) printf("%c", string_arr[i]);
    //printf("\n");
    return num;
}

void result(char ret[]) {
    for (int i = 0; i < t_size; i++) {
        ret[i] = string_arr[i];
    }
}

int found(int idx, char string_A[]) {
    //printf("found(%d)\n", idx);
    int p_size = strlen(string_A);
    int t_idx = idx, p_idx = 0;
    int skip[52];
    for (int i = 0; i < 52; i++) {
        skip[i] = -1;
    }
    for (int i = 0; i < p_size; i++) {
        skip[(int)string_A[i] - 'a'] = i;
    }
    bool found = true;
    while (t_idx <= t_size - p_size) {
        //printf("while\n");
        found = true;
        for (int p_idx = p_size - 1; p_idx >= 0; p_idx--) {
            //printf("t_idx: %d, p_idx: %d\n", t_idx, p_idx);
            if (string_arr[t_idx + p_idx] != string_A[p_idx]) {//다른 경우
                //printf("diff\n");
                found = false;
                t_idx += max(1, (p_idx - skip[string_arr[t_idx + p_idx] - 'a']));
                break;
            }
        }
        //printf("for루프 끝 p_idx: %d found: %d\n", p_idx, found);
        if (p_idx == 0 && found) {
            return t_idx;
        }
    }
    //if (found) return t_idx;
    return -1;
}