#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex; 
int arr[101][101];
vector<int> adj[101];
bool visited[101];
vector<int> lt[101];

void BFS(int u, int component) {
    queue<int> q;
    q.push(u);
    visited[u] = true; 
    lt[component].push_back(u);

    while(!q.empty()) {
        int x = q.front(); q.pop();
        for (int v : adj[x]) {
            if(!visited[v]) {
                lt[component].push_back(v);
                q.push(v);
                visited[v] = true;
            }
        }
    }
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
    memset(visited, false, sizeof(visited));

    int cnt = 0;
    for (int i = 1; i <= vertex; ++i) {
        if(!visited[i]) {
            ++cnt;
            BFS(i, cnt);
        }
    }

    cout << cnt << endl;
    for (int i = 1; i <= cnt; ++i) {
        sort(lt[i].begin(), lt[i].end());
        for (int x : lt[i]) cout << x << " ";
        cout << endl;
    }

    return 0;
}