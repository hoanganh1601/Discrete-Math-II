#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, st;
vector<int> adj[101];
bool visited[101];
vector<pair<int, int>> res;

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if(!visited[v]) {
            res.push_back({u, v});
            DFS(v);
        }
    }
}

void BFS() {
    queue<int> q;
    q.push(st);
    visited[st] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if(!visited[v]) {
                q.push(v);
                visited[v] = true;
                res.push_back({u, v});
            }
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);

    int t; cin >> t;
    cin >> vertex >> st;
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            int w; cin >> w;
            if(w) adj[i].push_back(j);
        }
    }
    memset(visited, false, sizeof(visited));

    if(t == 1) DFS(st);
    else if(t == 2) BFS();

    cout << res.size() << endl; 
    for (pair<int, int> x : res) {
        cout << min(x.first, x.second) << " " << max(x.first, x.second) << endl;
    }

    return 0;
}