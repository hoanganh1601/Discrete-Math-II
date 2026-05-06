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
        vector<int> adj[105];
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if(arr[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        cout << n << endl;

        for (int i = 1; i <= n; ++i) {
            cout << adj[i].size() << " ";
            for (int x : adj[i]) cout << x << " ";
            cout << endl;
        }
    }

    return 0;
}