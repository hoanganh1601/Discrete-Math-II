#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

struct Edge {
    int u, v, w;
};

struct cmpMin{
    bool operator()(const Edge &x, const Edge &y) {
        if(x.w != y.w) return x.w > y.w;
        if(x.u != y.u) return x.u > y.u;
        return x.v > y.v;
    }
};

struct cmpMax{
    bool operator()(const Edge &x, const Edge &y) {
        if(x.w != y.w) return x.w < y.w;
        if(x.u != y.u) return x.u > y.u;
        return x.v > y.v;
    }
};

int vertex, s; 
int mtx[105][105];
vector<Edge> res;
vector<Edge> adj[105];
bool taken[105];

void Prim(int t) {
    memset(taken, false, sizeof(taken));
    taken[s] = true;
    int ans = 0;
    
    if(t == 1) {
        priority_queue<Edge, vector<Edge>, cmpMin> q;    
        for (Edge tmp : adj[s]) {
            q.push(tmp);
        }

        while(!q.empty()) {
            Edge cur = q.top(); q.pop();
            int u = cur.u, v = cur.v, w = cur.w;

            if(!taken[v]) {
                taken[v] = true;
                ans += w;
                res.push_back(cur);

                for (Edge next : adj[v]) {
                    if(!taken[next.v]) {
                        q.push(next);
                    }
                }
            }
        }

        if(res.size() < vertex - 1) cout << 0;
        else {
            cout << ans << endl;
            for (Edge tmp : res) {
                cout << tmp.u << " " << tmp.v << " " << tmp.w << endl;
            }
        }
    }


    else if(t == 2) {
        priority_queue<Edge, vector<Edge>, cmpMax> q;
        for (Edge tmp : adj[s]) {
            q.push(tmp);
        }

        while(!q.empty()) {
            Edge cur = q.top(); q.pop();
            int u = cur.u, v = cur.v, w = cur.w;

            if(!taken[v]) {
                taken[v] = true;
                ans += w;
                res.push_back(cur);

                for (Edge next : adj[v]) {
                    if(!taken[next.v]) {
                        q.push(next);
                    }
                }
            }
        }

        if(res.size() < vertex - 1) cout << 0;
        else {
            cout << ans << endl;
            for (Edge tmp : res) {
                cout << tmp.u << " " << tmp.v << " " << tmp.w << endl;
            }
        }
    }

}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);

    int t; cin >> t;
    cin >> vertex >> s;
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            cin >> mtx[i][j];
            if(mtx[i][j] == 10000) mtx[i][j] = 0;
            if(mtx[i][j]) {
                adj[i].push_back({i, j, mtx[i][j]});
            }
        }
    }

    Prim(t);

    return 0;
}