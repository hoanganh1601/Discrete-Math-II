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
    int mtx[vertex + 1][vertex + 1];

    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) cin >> mtx[i][j];
    }

    if(t == 1) {
        vector<int> degIn(vertex + 1, 0), degOut(vertex + 1, 0);

        for (int i = 1; i <= vertex; ++i) {
            for (int j = 1; j <= vertex; ++j) {
                degIn[j] += mtx[i][j];
                degOut[i] += mtx[i][j];
            }
        }

        for (int i = 1; i <= vertex; ++i) {
            cout << degIn[i] << " " << degOut[i] << endl;
        }
    }

    else {
        vector<pair<int, int>> edges;
        for (int i = 1; i <= vertex; ++i) {
            for (int j = 1; j <= vertex; ++j) {
                if(mtx[i][j]) edges.push_back({i, j});
            }
        }

        int edge = edges.size();
        cout << vertex << " " << edge << endl;

        vector<vector<int>> res(vertex + 1, vector<int>(edge, 0));
        for (int i = 0; i < edge; ++i) {
            int u = edges[i].first, v = edges[i].second;
            res[u][i] = 1;
            res[v][i] = -1;
        }
        
        for (int i = 1; i <= vertex; ++i) {
            for (int j = 0; j < edge; ++j) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}