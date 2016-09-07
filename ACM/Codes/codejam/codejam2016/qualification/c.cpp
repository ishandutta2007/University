#include <bits/stdc++.h>

using namespace std;

const string str[5] = {
    "1001",
    "1100",
    "0110",
    "0011",
    "1111",
};

int T, cas, n, m, res[105];

void Dfs(int cur) {
    if (!m) return;
    if (cur == n / 4) {
        for (int i = 0; i < n / 4; i ++) {
            printf("%s", str[res[i]].c_str());
        }
        for (int i = 3; i <= 11; i ++) {
            printf(" %d", i);
        }
        puts("");
        m --;
        return;
    }
    for (int i = 0; i < 5; i ++) {
        if (cur == 0) {
            if (i == 2 || i == 3) continue;
        }
        if (cur == n / 4 - 1) {
            if (i == 1 || i == 2) continue;
        }
        res[cur] = i;
        Dfs(cur + 1);
    }
}

int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    cin >> T;
    while (T --) {
        scanf("%d%d", &n, &m);
        printf("Case #%d:\n", ++ cas);
        Dfs(0);
    }
}
