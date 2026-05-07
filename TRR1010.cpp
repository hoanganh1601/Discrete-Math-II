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

    int mtx[vertex + 1][vertex + 1];
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            cin >> mtx[i][j];
        }
    }

    if(t == 1) {
        for (int i = 1; i <= vertex; ++i) {
            int degree = 0;
            for (int j = 1; j <= vertex; ++j) {
                if(mtx[i][j] != 10000 && mtx[i][j] != 0) ++degree;
            }
            cout << degree << " ";
        }
    }

    else{
        vector<pair<int, int>> edges;
        for (int i = 1; i <= vertex; ++i) {
            for (int j = i + 1; j <= vertex; ++j) {
                if(mtx[i][j] != 10000 && mtx[i][j] != 0) edges.push_back({i, j});
            }
        }

        int edge = edges.size();
        cout << vertex << " " << edge << endl;
        
        for (auto x : edges) { 
            cout << x.first << " " << x.second << " " << mtx[x.first][x.second] << endl;
        }
    }

    return 0;
}

