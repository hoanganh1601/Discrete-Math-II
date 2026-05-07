#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

// Bai nay de sai, khong co nhap/xuat file dau nhe

int mtx[105][5000];
vector<pair<int, int>> edges;
int degree[105];

int main () {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int vertex; cin >> vertex;

    for (int i = 1; i <= vertex; ++i) {
        int sz; cin >> sz;
        degree[i] = sz;
        while(sz--) {
            int x; cin >> x;
            if(x > i) edges.push_back({i, x});
        }
    }

    if(t == 1) {
        for (int i = 1; i <= vertex; ++i) cout << degree[i] << ' ';
    }

    else{

        int edge = edges.size();
        cout << vertex << ' ' << edge << endl;

        for (int i = 0; i < edge; ++i) {
            int u = edges[i].first, v = edges[i].second;
            mtx[u][i] = 1;
            mtx[v][i] = 1;
        }

        for (int i = 1; i <= vertex; ++i) {
            for (int j = 0; j < edge; ++j) {
                cout << mtx[i][j] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}

