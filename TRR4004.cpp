#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, s;
int arr[101][101];
bool taken[101];
vector<pair<int, int>> adj[101];
vector<pair<int, int>> res;
int ans = 0;

void Prim(int s) {
    priority_queue<pair<int, pair<int, int>>, 
                    vector<pair<int, pair<int, int>>>, 
                    greater<pair<int, pair<int, int>>>> q;
    taken[s] = true;

    for (pair<int, int> tmp : adj[s]) {
        if(!taken[tmp.second]) {
            q.push({tmp.first, {s, tmp.second}});
        }
    }

    // duyet
    while(!q.empty()) {
        pair<int, pair<int, int>> tmp = q.top(); q.pop();
        int u = tmp.second.first, v = tmp.second.second, weight = tmp.first;

        if(!taken[v]) {

            taken[v] = true;
            ans += weight;
            res.push_back({min(u, v), max(u, v)});

            for (auto pa : adj[v]) {
                if(!taken[pa.second]) {
                    q.push({pa.first, {v, pa.second}});
                }
            }
        }  
    }

    cout << ans << endl;
    for (auto x : res) {
        cout << x.first << " " << x.second << " " << arr[x.first][x.second] << endl;
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);

    cin >> vertex >> s;
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] > 0 && arr[i][j] <= 50) {
                adj[i].push_back({arr[i][j], j});
            }
        }
    }
    memset(taken, false, sizeof(taken));

    Prim(s);

    return 0;
}