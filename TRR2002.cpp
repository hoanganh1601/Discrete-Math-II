#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, u, v;
int arr[101][101];
vector<int> adj[101];
bool visited[101];
int parent[101];

void BFS(int u, int v) {
    visited[u] = true;
    
    queue<int> q;
    q.push(u);

    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(x == v) return;

        for (int y : adj[x]) {
            if(!visited[y]) {
                parent[y] = x;
                q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);

    int t;
    cin >> t;
    cin >> vertex >> u >> v;
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            cin >> arr[i][j];
            if(arr[i][j]) adj[i].push_back(j);
        }
    }

    if(t == 1) {
        int cnt = 0;
        for (int i = 1; i <= vertex; ++i) {
            if(arr[u][i] && arr[i][v]) {
                ++cnt;
            }
        }
        cout << cnt << endl;
    }

    else {
        memset(visited, false, sizeof(visited));
        BFS(u, v);

        if(!visited[v]) cout << 0 << endl;
        else {
            vector<int> res;
            res.reserve(vertex + 1);

            while(v != u) {
                res.push_back(v);
                v = parent[v];
            }
            res.push_back(u);

            reverse(res.begin(), res.end());
            for (int x : res) cout << x << " ";
        }
    }


    return 0;
}