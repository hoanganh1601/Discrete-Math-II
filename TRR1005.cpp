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

    vector<pair<int, int>> edges(edge + 1);
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
        cout << vertex << endl;
        vector<int> adj[vertex + 1];

        for (auto edge : edges) {
            int u = edge.first, v = edge.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= vertex; ++i) {
            cout << adj[i].size() << " ";
            for (int x : adj[i]) cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}