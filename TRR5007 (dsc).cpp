#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Edge {
    int u, v, w;
};

int vertex, s, t;
int mtx[105][105];
vector<Edge> edgeList;

void BellmanFord(){
    vector<int> d(105, (int)1e9), e(105, s);
    d[s] = 0;

    // Loop n - 1 times
    for (int i = 1; i <= vertex - 1; ++i) {
        bool ok = false;
        for (Edge tmp : edgeList) {
            int u = tmp.u, v = tmp.v, w = tmp.w;
    
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                e[v] = u;
                ok = true;
            }

            // do thi vo huong
            // if(d[u] > d[v] + w) {
            //     d[u] = d[v] + w;
            //     e[u] = v;
            //     ok = true;
            // }
        }
        if(!ok) break;
    }

    // Check negative cycles
    bool neg = false;
    for (Edge tmp : edgeList) {
        if(d[tmp.v] > d[tmp.u] + tmp.w) {
            neg = true;
            break;
        }
    }

    if(neg) cout << -1;
    else if(d[t] == (int)1e9) cout << 0;
    else {
        vector<int> path;
        path.reserve(vertex + 5);

        int cur = t;
        while(cur != s) {
            path.push_back(cur);
            cur = e[cur];
        }
        path.push_back(s);

        reverse(path.begin(), path.end());

        cout << d[t] << endl;
        for (int x : path) cout << x << " ";
    }   
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("BN.INP", "r", stdin);
    // freopen("BN.OUT", "w", stdout);

    cin >> vertex >> s >> t;
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            cin >> mtx[i][j];
            if(mtx[i][j] != 0 && mtx[i][j] != 10000) {
                edgeList.push_back({i, j, mtx[i][j]});
            }
        }
    }

    BellmanFord();

    return 0;
}