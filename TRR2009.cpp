#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex;
int mtx[105][105];
vector<int> adj[105];
vector<int> lt[105];
bool visited[105];

void DFS(int u, int st) {
    visited[u] = true;
    lt[st].push_back(u);
    for (int x : adj[u]) {
        if(!visited[x]) {
            DFS(x, st);
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
            cin >> mtx[i][j];
            if(mtx[i][j]) adj[i].push_back(j);
        }
    }
    
    memset(visited, false, sizeof(visited));
    
    int ans = 0;
    for (int i = 1; i <= vertex; ++i) {
        if(!visited[i]) {
            ++ans;
            DFS(i, ans);
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= ans; ++i) {
        sort(lt[i].begin(), lt[i].end());
        for (int x : lt[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}