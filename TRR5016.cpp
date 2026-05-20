#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex;
int arr[101][101];
int dist[101][101];
int parent[101][101];

void Floyd() {

    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            dist[i][j] = arr[i][j];
            parent[i][j] = i;
        }
    }
    
    for (int k = 1; k <= vertex; ++k) {
        for (int i = 1; i <= vertex; ++i) {
            for (int j = 1; j <= vertex; ++j) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    parent[i][j] = parent[k][j]; // IMPORTANT
                }
            }
        }
    }
    
    int maxVal = -1;
    pair<int, int> res;

    // Find the maximum shortest path
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            if(dist[i][j] != (int)1e9 && i != j) {
                if(maxVal < dist[i][j]) {
                    maxVal = dist[i][j];
                    res = {i, j};
                }
            }
        }
    }

    if(maxVal != -1) {
        cout << res.first << " " << res.second << " " << maxVal << endl;
        
        int cur = res.second;
        vector<int> path;
        while(cur != res.first) {
            path.push_back(cur);
            cur = parent[res.first][cur];
        }
        path.push_back(cur);

        reverse(path.begin(), path.end());
        for (int x : path) cout << x << " ";
    }    
    else cout << 0; 
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("DN.INP", "r", stdin);
    // freopen("DN.OUT", "w", stdout);

    cin >> vertex;
    for(int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] == 0 || arr[i][j] == 10000) arr[i][j] = (int)1e9;
        }
    }

    Floyd();

    return 0;
}