#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main () {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int vertex; cin >> vertex;

    vector<vector<int>> mtx(vertex + 1, vector<int>(vertex + 1, 0));
    vector<int> degree(vertex + 1, 0);

    for (int i = 1; i <= vertex; ++i) {
        int sz; cin >> sz;
        degree[i] = sz;
        while(sz--) {
            int x; cin >> x;
            mtx[i][x] = 1;
            mtx[x][i] = 1;
        }
    }

    if(t == 1) {
        for (int i = 1; i <= vertex; ++i) cout << degree[i] << " ";
    }

    else if(t == 2) {
        cout << vertex << endl;
        for (int i = 1; i <= vertex; ++i) {
            for (int j = 1; j <= vertex; ++j) {
                cout << mtx[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}