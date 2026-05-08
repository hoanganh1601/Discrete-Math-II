#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

struct Edge {
    int u, v, weight;
};

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int vertex, edge; cin >> vertex >> edge;
    vector<Edge> edges;

    for (int i = 1; i <= edge; ++i) {
        Edge x;
        cin >> x.u >> x.v >> x.weight;
        edges.push_back(x);
    }

    if(t == 1) {
        vector<int> degree(vertex + 1, 0);
        for (Edge x : edges) {
            ++degree[x.u];
            ++degree[x.v];
        }

        for (int i = 1; i <= vertex; ++i) cout << degree[i] << " ";
    }
    
    else {
        vector<vector<int>> mtx(vertex + 1, vector<int>(vertex + 1, 10000));
        for (Edge x : edges) {
            mtx[x.u][x.v] = x.weight;
            mtx[x.v][x.u] = x.weight;
        }

        cout << vertex << endl;
        for (int i = 1; i <= vertex; ++i) {
            mtx[i][i] = 0;
            for (int j = 1; j <= vertex; ++j) {
                cout << mtx[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
