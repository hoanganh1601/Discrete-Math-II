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

    vector<int> degIn(vertex + 1, 0), degOut(vertex + 1, 0);
    vector<Edge> edges;

    for (int i = 1; i <= edge; ++i) {
        Edge x;
        cin >> x.u >> x.v >> x.weight;
        edges.push_back(x);
        ++degOut[x.u]; ++degIn[x.v];
    }


    if(t == 1) {
        for (int i = 1; i <= vertex; ++i) {
            cout << degIn[i] << " " << degOut[i] << endl;
        }
    }

    else {
        cout << vertex << endl;
        vector<vector<int>> res(vertex + 1, vector<int>(vertex + 1, 10000));
        for (Edge x : edges) {
            res[x.u][x.v] = x.weight;
        }

        for (int i = 1; i <= vertex; ++i) {
            res[i][i] = 0;
            for (int j = 1; j <= vertex; ++j) cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}