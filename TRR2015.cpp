#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex;
int arr[101][101];
bool visited[101];
vector<int> adj[101];
vector<int> unAdj[101];

void DFS(int u, vector<int> x[]) {
    visited[u] = true;
    for (int v : x[u]) {
        if(!visited[v]) DFS(v, x);
    }
}

bool StronglyConnected() {
    for (int i = 1; i <= vertex; ++i) {
        memset(visited, false, sizeof(visited));
        DFS(i, adj);
        for (int j = 1; j <= vertex; ++j) {
            if(!visited[j]) return false;
        }
    }
    return true;
}

bool WeeklyConnected() {
    memset(visited, false, sizeof(visited));
    DFS(1, unAdj);
    for (int i = 1; i <= vertex; ++i) {
        if(!visited[i]) return false;
    }
    return true;
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
            if(arr[i][j]) {
                adj[i].push_back(j);
                
                unAdj[i].push_back(j);
                unAdj[j].push_back(i);
            }
        }
    }

    if(StronglyConnected()) cout << 1 << endl;
    else if(WeeklyConnected()) cout << 2 << endl;
    else cout << 0 << endl;

    return 0;
}