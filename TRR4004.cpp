#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Edge {
    int u, v, w;
    
    bool operator > (const Edge& other) const {
        if(w != other.w) return w > other.w;
        if(u != other.u) return u > other.u;
        return v > other.v;
    }
};

int vertex, start;
int mtx[105][105];
vector<Edge> adj[105];
vector<Edge> res;
bool taken[105];

int ans = 0;

void Prim(int start) {
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    taken[start] = true; // Đỉnh xuất phát

    // Đẩy tất cả các đỉnh có thể 
    for (Edge tmp : adj[start]) {
        if(!taken[tmp.v]) {
            q.push(tmp);
        }
    }

    while(!q.empty()) {
        Edge cur = q.top(); q.pop();

        int u = cur.u, v = cur.v, w = cur.w;
        if(!taken[v]) {
            taken[v] = true;
            ans += w;

            res.push_back({min(u, v), max(u, v), w});
            for (Edge next : adj[v]) {
                if(!taken[next.v]) {
                    q.push(next);
                }
            }
        }
    }

    if(res.size() < vertex - 1) {
        cout << 0;
        return;
    }

    cout << ans << endl;
    for (Edge x : res) {
        cout << x.u << " " << x.v << " " << x.w << endl;
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);

    cin >> vertex >> start;
    res.reserve(10005);
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            cin >> mtx[i][j];
            if(mtx[i][j] > 0 && mtx[i][j] <= 50) {
                adj[i].push_back({i, j, mtx[i][j]});
            }
        }
    }

    memset(taken, false, sizeof(taken));

    Prim(start);

    return 0;
}