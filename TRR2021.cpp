#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int vertex; 
bool visited[101];
int arr[101][101];
vector<int> adj[101];

void DFS(int u, int stop) {
    visited[u] = true;
    for (int v : adj[u]) {
        if(v == stop) continue;
        
        if(!visited[v]) {
            DFS(v, stop);
        }
    }
}

int tplt(int stop) {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for (int i = 1; i <= vertex; ++i) {
        if(i == stop) continue;
        
        if(!visited[i]) {
            ++cnt;
            DFS(i, stop);
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
            if(arr[i][j]) adj[i].push_back(j);
        }
    }

    int cnt = 0;
    vector<int> bridges;
    bridges.reserve(vertex);

    memset(visited, false, sizeof(visited));
    int cc = tplt(-1);

    for (int i = 1; i <= vertex; ++i) {
        int tmp = tplt(i);
        if(tmp > cc) bridges.push_back(i);
    }

    cout << bridges.size() << endl;
    for (int x : bridges) cout << x << " ";

    return 0;
}