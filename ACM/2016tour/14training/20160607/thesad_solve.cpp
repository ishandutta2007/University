#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 400010
int u[2][MAX];
int s[MAX];
int main(){
    freopen("in.txt", "r", stdin);
    int T, n, m, L, i, x, k, l, ri = 1;
    long long ans, t;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &n, &m, &L);
        memset(s, 0, sizeof(s));
        memset(u, 0, sizeof(u));
        for (i = 0; i < n; i++){
            scanf("%d%d%d", &x, &k, &l);
            x *= 4; l *= 4;
            if (k == 1) u[0][x] = max(u[0][x], l);
            else u[1][x] = max(u[1][x], l * 3);
        }
        int p = 0, q = 0;
        for (i = 400000; i > 0; i--){
            p = max(p, u[0][i]);
            q = max(q, u[1][i]);
            s[i - 1] = max(s[i - 1], p + p - 1);
            s[i - 1] = max(s[i - 1], q + q - 3);
            p--;
            q -= 3;
        }
        memset(u, 0, sizeof(u));
        for (i = 0; i < m; i++){
            scanf("%d%d%d", &x, &k, &l);
            x *= 4; l *= 4;
            if (k == 1) u[0][x] = max(u[0][x], l);
            else u[1][x] = max(u[1][x], l * 3);
        }
        p = q = 0;
        for (i = 0; i < 400000; i++){
            p = max(p, u[0][i]);
            q = max(q, u[1][i]);
            s[i] = max(s[i], p + p - 1);
            s[i] = max(s[i], q + q - 3);
            p--;
            q -= 3;
        }
        ans = t = 0;
        L *= 4;
        for (i = 0; i < L; i++){
            t += s[i];
        }
        ans = t;
        for (i = 0; i + L < 400000; i++){
            t += s[i + L] - s[i];
            ans = max(ans, t);
        }
        printf("Case #%d: %.6f\n", ri++, ans / 32.0);
    }
    return 0;
}
