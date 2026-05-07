#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main () {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int vertex; cin >> vertex;

    vector<int> degree(vertex + 1, 0);
    vector<pair<int, int>> edges;

    for (int i = 1; i <= vertex; ++i) {
        int sz; cin >> sz;
        degree[i] = sz;
        while(sz--) {
            int x; cin >> x;
            if(x > i) edges.push_back({i, x});
        }
    }

    if(t == 1) {
        for (int i = 1; i <= vertex; ++i) cout << degree[i] << " ";
    }

    else if(t == 2) {
        cout << vertex << " " << edges.size() << endl;
        for (auto x : edges) {
            cout << x.first << " " << x.second << endl;
        }
    }

    return 0;
}