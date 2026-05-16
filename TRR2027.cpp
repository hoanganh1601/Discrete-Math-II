#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int vertex; 
bool visited[101];
int arr[101][101];
vector<int> adj[101];
vector<pair<int, int>> edges;

void DFS(int u, int start, int stop) {
    visited[u] = true;
    for (int v : adj[u]) {
        if((v == start && u == stop) || (u == start && v == stop)) continue;

        if(!visited[v]) DFS(v, start, stop);
    }
}

int tplt(int u, int v) {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= vertex; ++i) {
        if(!visited[i]) {
            ++cnt;
            DFS(i, u, v);
        }
    }

    return cnt;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);

    cin >> vertex;
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] && j > i) {
                edges.push_back({i, j});
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }


    vector<pair<int, int>> bridges;
    int cc = tplt(-1, -1); // no remove;

    for (pair<int, int> x : edges) {
        int tmp = tplt(x.first, x.second);
        if(tmp > cc) bridges.push_back({x.first, x.second});
    }

    cout << bridges.size() << endl;
    for (pair<int, int> x : bridges) {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}