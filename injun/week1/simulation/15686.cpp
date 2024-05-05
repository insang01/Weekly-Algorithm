#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <limits.h>

using namespace std;

int n, m, houseCnt, chickenCnt, res = 2147000000;
int houseX[100], houseY[100];
int chickenX[13], chickenY[13], visited[13], selected[13];

void dfs(int depth, int cur)
{
    if (depth == m) {
        int dis, minDis, sum = 0;
        for (int i = 0; i < houseCnt; i++) {
            minDis = 2147000000;
            for (int j = 0; j < m; j++) {
                dis = abs(houseY[i] - chickenY[selected[j]]) + abs(houseX[i] - chickenX[selected[j]]);
                if (dis < minDis) {
                    minDis = dis;
                }
            }
            sum += minDis;
        }
        if (sum < res) {
            res = sum;
        }
    } else {
        for (int i = cur; i < chickenCnt; i++) {
            if (!visited[i]) {
                visited[i] = 1;
                selected[depth] = i;
                dfs(depth + 1, i);
                visited[i] = 0;
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tmp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp == 1) {
                houseY[houseCnt] = i;
                houseX[houseCnt++] = j;
            } else if (tmp == 2) {
                chickenY[chickenCnt] = i;
                chickenX[chickenCnt++] = j;
            }
        }
    }
    dfs(0, 0);
    cout << res;

    return 0;
}