#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, s, t;
int arr[101][101];

void BellmanFord() {
    vector<int> dist(vertex + 1, 1e9);
    vector<int> parent(vertex + 1, s);

    dist[s] = 0;
    for (int i = 1; i <= vertex - 1; ++i) {
        bool ok = false;
        for (int u = 1; u <= vertex; ++u) {
            for (int v = 1; v <= vertex; ++v) {
                if(dist[u] != (int)1e9 && arr[u][v] != (int)1e9 && dist[v] > dist[u] + arr[u][v]) {
                    dist[v] = dist[u] + arr[u][v];
                    parent[v] = u;
                    ok = true;
                }
            }
        }
        if(!ok) break;
    }

    // Step 1: Check for negative weight cycles
    bool negative = false;
    for(int u = 1; u <= vertex; ++u) {
        for (int v = 1; v <= vertex; ++v) {
            if(dist[u] != 1e9 && arr[u][v] != 1e9 && dist[v] > dist[u] + arr[u][v]) {
                negative = true;
                break;
            }
        }
    }

    if(negative) cout << -1;
    else if(dist[t] == (int)1e9) cout << 0;
    else {
        vector<int> res;
        int cur = t;
        
        while(cur != s) {
            res.push_back(cur);
            cur = parent[cur];
        }
        res.push_back(s);

        reverse(res.begin(), res.end());

        cout << dist[t] << endl;
        for (int x : res) cout << x << " ";
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
            cin >> arr[i][j];
            if(arr[i][j] == 0 || arr[i][j] == 10000) arr[i][j] = (int)1e9;
        }
    }

    BellmanFord();

    return 0;
}