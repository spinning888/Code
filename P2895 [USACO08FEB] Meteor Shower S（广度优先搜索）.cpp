#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int m, x, y, t, tx, ty;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct node {
    int x, y, t, step;
    bool vis;
};

node p[305][305];

void bfs(node& s) {
    queue<node> q;
    q.push(s);
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            tx = u.x + dx[i];
            ty = u.y + dy[i];
            // 如果移动到超过301的坐标，视为安全区域
            if (tx > 301 || ty > 301) {
                cout << u.step + 1 << endl;
                return;
            }
            // 检查边界和访问状态
            if (tx < 1 || ty < 1 || tx >= 305 || ty >= 305 || p[tx][ty].vis) 
                continue;
            // 检查是否安全
            if (p[tx][ty].t == -1) {
                cout << u.step + 1 << endl;
                return;
            }
            // 检查是否能在被摧毁前到达
            if (u.step + 1 < p[tx][ty].t) {
                p[tx][ty].vis = true;
                p[tx][ty].step = u.step + 1;
                q.push(p[tx][ty]);
            }
        }
    }
    cout << -1 << endl;
}

void solve() {
    cin >> m;
    // 初始化每个节点
    for (int i = 0; i < 305; i++) {
        for (int j = 0; j < 305; j++) {
            p[i][j].x = i;
            p[i][j].y = j;
            p[i][j].t = -1;
            p[i][j].vis = false;
            p[i][j].step = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> t;
        x++;
        y++;
        for (int j = 0; j < 5; j++) { // 包括自己和四个方向
            int dirx = (j < 4) ? dx[j] : 0;
            int diry = (j < 4) ? dy[j] : 0;
            tx = x + dirx;
            ty = y + diry;
            if (tx >= 1 && tx < 305 && ty >= 1 && ty < 305) {
                if (p[tx][ty].t == -1 || t < p[tx][ty].t) {
                    p[tx][ty].t = t;
                }
            }
        }
    }
    // 检查起点是否安全
    if (p[1][1].t == -1) {
        cout << 0 << endl;
        return;
    }
    if (p[1][1].t == 0) {
        cout << -1 << endl;
        return;
    }
    // 初始化起点
    p[1][1].vis = true;
    p[1][1].step = 0;
    bfs(p[1][1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
