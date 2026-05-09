#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int vertex; cin >> vertex;
    int mtx[vertex + 1][vertex + 1];
    
    vector<int> degIn(vertex + 1, 0), degOut(vertex + 1, 0);
    vector<pair<int, int>> edges;
    
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            cin >> mtx[i][j];
            if(mtx[i][j] != 10000 && mtx[i][j] != 0) {
                edges.push_back({i, j});
                ++degOut[i];
                ++degIn[j];
            }
        }
    }

    if(t == 1) {
        for (int i = 1; i <= vertex; ++i) {
            cout << degIn[i] << " " << degOut[i] << endl;
        }
    }

    else {
        int edge = edges.size();
        cout << vertex << " " << edge << endl;
        for (pair<int, int> x : edges) {
            cout << x.first << " " << x.second << " " << mtx[x.first][x.second] << endl;
        }
    }

    return 0;
}