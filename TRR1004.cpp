#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int n, m; cin >> n >> m;
    vector<pair<int, int>> edgeList;

    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edgeList.push_back({u, v});
    }

    if(t == 1) {    

        vector<int> degree(105, 0);
        for (auto edge : edgeList) {
            ++degree[edge.first];
            ++degree[edge.second];
        }

        for (int i = 1; i <= n; ++i) {
            cout << degree[i] << " ";
        }
    }

    else if(t == 2) {
        int mtx[101][101];
        for (auto edge : edgeList) {
            int x = edge.first, y = edge.second;
            mtx[x][y] = 1;
            mtx[y][x] = 1;
        }

        cout << n << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << mtx[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}