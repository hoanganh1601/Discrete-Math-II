#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, u;
int arr[101][101];
vector<int> adj[101];
int degIn[101], degOut[101];
bool visited[101];

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if(!visited[v]) {
            DFS(v);
        }
    }
}

bool isComponent() {
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= vertex; ++i) {
        if(!visited[i]) {
            ++cnt;
            if(cnt > 1) return false;
            DFS(i);
        }
    }
    return true;
}

int isEuler() {
    if(!isComponent()) return 0;

    int cnt = 0;
    for (int i = 1; i <= vertex; ++i) {
        if(degIn[i] != degOut[i]) ++cnt;   
    }

    if(cnt == 0) return 1;
    else if(cnt == 2) return 2;
    return 0;
}

int main() {

    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    int t; cin >> t;
    if(t == 1) {
        cin >> vertex; 
        for (int i = 1; i <= vertex; ++i) {
            for (int j = 1; j <= vertex; ++j) {
                cin >> arr[i][j];
                if(arr[i][j]) {
                    ++degOut[i];
                    ++degIn[j];
                    adj[i].push_back(j);
                }
            }
        }

        cout << isEuler();
    }

    else {
        cin >> vertex >> u;
        for (int i = 1; i <= vertex; ++i) {
            for (int j = 1; j <= vertex; ++j) cin >> arr[i][j];
        }

        stack<int> st;
        vector<int> res;
        st.push(u);
        int cur = u;
        
        while(!st.empty()) {
            if(st.size() > 0) cur = st.top();

            bool hasEdge = false;
            for (int i = 1; i <= vertex; ++i) {
                if(arr[cur][i]) {
                    st.push(i);
                    arr[cur][i] = 0;
                    hasEdge = true;

                    break;
                }
            }

            if(!hasEdge) {
                res.push_back(cur);
                st.pop();
            }
        }

        reverse(res.begin(), res.end());

        for (int x : res) cout << x << " ";
    }

    return 0;
}