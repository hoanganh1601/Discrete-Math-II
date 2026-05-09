#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int vertex; cin >> vertex;

    vector<int> degIn(vertex + 1, 0), degOut(vertex + 1, 0);
    vector<vector<int>> res(vertex + 1, vector<int>(vertex + 1, 0));

    for (int i = 1; i <= vertex; ++i) {
        int sz; cin >> sz;
        degOut[i] += sz;
        while(sz--) {
            int u; cin >> u;
            ++degIn[u];
            res[i][u] = 1;
        }
    }

    if(t == 1) {
        for (int i = 1; i <= vertex; ++i) {
            cout << degIn[i] << " " << degOut[i] << endl;
        }
    }

    else {
        cout << vertex << endl;
        for (int i = 1; i <= vertex; ++i) {
            for (int j = 1; j <= vertex; ++j) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}