#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
using ll = long long;


int degree[105];

int main () {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t; cin >> t;
    int n; cin >> n;
    int arr[105][105]; 

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> arr[i][j];
        }
    }

    if(t == 1) {
        for (int i = 1; i <= n; ++i) {
            int degree = 0;
            for (int j = 1; j <= n; ++j) {
                degree += arr[i][j];
            }
            cout << degree << " ";
        }
    }
    else if(t == 2) {
        // convert Edge list
        vector<pair<int, int>> edges; // start, end
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if(arr[i][j]) {
                    edges.push_back({i, j});
                }
            }
        }

        cout << n << " " << edges.size() << endl;
        for (pair<int, int> edge : edges) {
            cout << edge.first << " " << edge.second << endl;
        }
    }

    return 0;
}