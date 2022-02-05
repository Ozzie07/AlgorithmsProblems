#include <bits/stdc++.h>
using namespace std;

int numOfBuilding[25 * 25];
int Visited[25][25];
int Input[25][25];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N;
int num;

void BFS(int x, int y, int cnt) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    Visited[x][y] = cnt;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        num++;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (Input[nx][ny] == 1 && Visited[nx][ny] == 0) {
                    Visited[nx][ny] = cnt;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return;
}

int main() {


    int i, j, cnt = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            scanf("%1d", &Input[i][j]); //getInput
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (Input[i][j] == 1 && Visited[i][j] == 0) {
                num = 0;
                BFS(i, j, ++cnt);
                numOfBuilding[cnt-1] = num;
            }
        }
    }

    printf("%d\n", cnt);
    if (!cnt)
        printf("%d\n", cnt);
    else
    {
        sort(numOfBuilding, numOfBuilding + cnt);
        for (i = 0; i < cnt; i++)
            printf("%d\n", numOfBuilding[i]);
    }
        
    return 0;
}