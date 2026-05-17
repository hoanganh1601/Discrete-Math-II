#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, u;
int arr[101][101];
int path[101];
bool visited[101];
int cnt;

void display() {
    for (int i = 1; i <= vertex; ++i) {
        cout << path[i] << " "; 
    } 
    cout << path[1] << endl;
    ++cnt;
}

void Hamilton(int k) {
    for (int i = 1; i <= vertex; ++i) {
        if(arr[path[k - 1]][i] == 1) {
            if(k == vertex + 1) {
                if(i == path[1]) {
                    display();
                }
            }

            else {
                if(!visited[i]) {
                    visited[i] = true;
                    path[k] = i;

                    Hamilton(k + 1);
                    
                    visited[i] = false;
                }
            }
        }
    }
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    cin >> vertex >> u;
    for (int i = 1; i <= vertex; ++i) {
        for (int j = 1; j <= vertex; ++j) cin >> arr[i][j];
    }
    memset(visited, false, sizeof(visited));
    cnt = 0;

    path[1] = u;
    visited[u] = true;
    Hamilton(2); 

    if(!cnt) cout << 0;
    else cout << cnt;

    return 0;
}