#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

using ii = pair<int, int>;

int vertex, s, t;
int weight[101][101];
vector<ii> adj[101];

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DN.INP", "r", stdin);
    // freopen("DN.OUT", "w", stdout);
    cin >> vertex >> s >> t;
    
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            cin >> weight[i][j];
            if(weight[i][j] == 10000) weight[i][j] = 0;
            
            if(weight[i][j]) {
                adj[i].push_back({j, weight[i][j]});
            }
        }
    }

    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    vector<int> d(vertex + 1, (int)1e9); d[s] = 0;
    vector<int> e(vertex + 1, 0); e[s] = s;

    while(!q.empty()) {
        ii x = q.top(); q.pop();
        int dis = x.first; // weight;
        int u = x.second;
        if(dis > d[u]) continue;

        for (ii edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                e[v] = u;
                q.push({d[v], v});
            }
        }
    }

    if(e[t] == 0) cout << 0;
    else {
        cout << d[t] << endl;
        // path 
        vector<int> path;
        int cur = t;
        while(cur != s) {
            path.push_back(cur);
            cur = e[cur];
        }

        path.push_back(cur);
        reverse(path.begin(), path.end());

        for (int x : path) cout << x << " ";
    }

    return 0;
}