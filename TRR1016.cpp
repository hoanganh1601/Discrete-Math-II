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
    int vertex, edge; cin >> vertex >> edge;
    vector<int> adj[vertex + 1];
    vector<int> degIn(vertex + 1, 0), degOut(vertex + 1, 0);

    for (int i = 1; i <= edge; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        ++degIn[v];
        ++degOut[u];
    }

    if(t == 1) {
        for (int i = 1; i <= vertex; ++i) {
            cout << degIn[i] << " " << degOut[i] << endl;    
        }
    }

    else {
        cout << vertex << endl;
        for (int i = 1; i <= vertex; ++i) {
            cout << adj[i].size() << " ";
            for (int x : adj[i]) cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}