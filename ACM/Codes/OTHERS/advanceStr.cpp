#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 7;

string s[N], t;

int last[N][26], tot;

bool Gao() {
    int n = t.length();
    memset(last, -1, sizeof(last));
    for (int i = n - 1; i >= 0; i --)
        for (int j = 0; j < 26; j ++) {
            if (t[i] - 'a' == j) {
                last[i][j] = i;
            } else {
                last[i][j] = last[i + 1][j];
            }
        }
    for (int i = 0; i < tot; i ++) {
        bool flag = true;
        int cur = 0;
        for (int j = 0; j < s[i].length(); j ++) {
            int id = s[i][j] - 'a';
            cur = last[cur][id];
            if (cur == -1) {
                flag = false;
                break;
            }
            else cur ++;
        }
        if (flag) cout << "TRUE" << endl;
        else cout << "FALSE" << endl;
    }
}

int main() {
    int n;
    cin >> tot;
    for (int i = 0; i < tot; i ++)
        cin >> s[i];
    cin >> t;
    Gao();
}
