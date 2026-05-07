#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int main () {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int vertex, edge; cin >> vertex >> edge;

    vector<pair<int, int>> edges;
    for (int i = 1; i <= edge; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    if(t == 1) {
        vector<int> degree(vertex + 1, 0);
        for(auto edge : edges) {
            ++degree[edge.first];
            ++degree[edge.second];
        }

        for (int i = 1; i <= vertex; ++i) cout << degree[i] << " ";
    }

    else if(t == 2) {
        cout << vertex << " " << edge << endl;

        vector<vector<int>> mtx(vertex + 1, vector<int>(edge + 1, 0));
        for (int k = 0; k < edge; ++k) {
            int u = edges[k].first, v = edges[k].second;
            mtx[u][k] = 1; mtx[v][k] = 1;
        }

        for (int i = 1; i <= vertex; ++i) {
            for (int j = 0; j < edge; ++j) {
                cout << mtx[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}