#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
using ll = long long;

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int n; cin >> n;
    int arr[105][105];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin >> arr[i][j];
    }

    if(t == 1) {
        for (int i = 1; i <= n; ++i) {
            int degree = 0;
            for (int j = 1; j <= n; ++j) degree += arr[i][j]; 
            cout << degree << " ";
        }
    }

    else if(t == 2) {
        vector<pair<int, int>> edges;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if(arr[i][j]) edges.push_back({i, j});
            }
        }

        int m = edges.size();
        cout << n << " " << m << endl;
        vector<vector<int>> inc(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < m; ++i) {
            int u = edges[i].first;
            int v = edges[i].second;

            inc[u][i] = 1;
            inc[v][i] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << inc[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}