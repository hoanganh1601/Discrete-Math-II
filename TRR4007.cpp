#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Edge {
    int x, y, weight;
};

int vertex, edge;
int parent[101], sz[101];
vector<Edge> edgeList;

bool cmp(Edge x, Edge y) {
    return x.weight < y.weight;
}

int Find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) return false;

    if(sz[u] < sz[v]) {
        parent[u] = v;
        sz[v] += sz[u];
    }

    else {
        parent[v] = u;
        sz[u] += sz[v];
    }

    return true;
}

void Kruskal() {
    vector<Edge> MST;
    int res = 0;

    for (Edge tmp : edgeList) {
        if(MST.size() == vertex - 1) break;
        if(Union(tmp.x, tmp.y)) {
            res += tmp.weight;
            MST.push_back(tmp);
        }
    }

    if(MST.size() < vertex - 1) {
        cout << 0;
        return;
    }
    cout << res << endl;
    for (Edge tmp : MST) {
        cout << tmp.x << " " << tmp.y << " " << tmp.weight << endl;
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);

    cin >> vertex >> edge;
    for (int i = 1; i <= vertex; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= edge; ++i) {
        Edge tmp;
        cin >> tmp.x >> tmp.y >> tmp.weight;
        edgeList.push_back(tmp);
    }
    stable_sort(edgeList.begin(), edgeList.end(), cmp);
    Kruskal();

    return 0;
}