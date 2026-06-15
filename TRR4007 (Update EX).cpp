 #include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Edge {
    int u, v, w;
};

int cmpMin(Edge x, Edge y) {
    if(x.w != y.w) return x.w < y.w;
    if(x.u != y.u) return x.u < y.u;
    return x.v < y.v;
}

int cmpMax(Edge x, Edge y) {
    if(x.w != y.w) return x.w > y.w;
    if(x.u != y.u) return x.u < y.u;
    return x.v < y.v;
}


int vertex, edge;
vector<Edge> res;
int par[105], sz[10005];

void init() {
    for (int i = 1; i <= vertex; ++i) {
        par[i] = i;
        sz[i] = 1;
    }
}

int Find(int u) {
    if(u == par[u]) return u;
    return par[u] = Find(par[u]);
}

bool Union(int u, int v) {
    u = Find(u); v = Find(v);
    if(u == v) return false;

    if(sz[u] > sz[v]) {
        sz[u] += sz[v];
        par[v] = u;
    }

    else {
        sz[v] += sz[u];
        par[u] = v;
    }

    return true;
} 

void Kruskal() {
    vector<Edge> MST;
    MST.reserve(vertex + 5);
    int ans = 0;

    for (Edge tmp : res) {
        if(MST.size() == vertex - 1) break;
        if(Union(tmp.u, tmp.v)) {
            ans += tmp.w;
            MST.push_back(tmp);
        }   
    }

    if(MST.size() < vertex - 1) cout << 0;
    else {
        cout << ans << endl;
        for (Edge tmp : MST) {
            cout << min(tmp.u, tmp.v) << " " << max(tmp.u, tmp.v) << " " << tmp.w << endl;
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);

    int t; cin >> t;
    cin >> vertex >> edge;
    for (int i = 1; i <= edge; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        res.push_back({u, v, w});
    }

    init();
    if(t == 1) {
        stable_sort(res.begin(), res.end(), cmpMin);
    }

    else if(t == 2) {
        stable_sort(res.begin(), res.end(), cmpMax);
    }

    Kruskal();

    return 0;
}