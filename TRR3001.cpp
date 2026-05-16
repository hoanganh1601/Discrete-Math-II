#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, u;
int arr[101][101];
vector<int> adj[101];
vector<int> deg(101, 0);
bool visited[101];

void DFS(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if(!visited[v]) DFS(v);
    }
}

// CHECK (DK can)
bool isComponent() {
    memset(visited, false, sizeof(visited));
    int cnt = 0;
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

    int odd = 0;
    for (int i = 1; i <= vertex; ++i) {
        if(deg[i] % 2 == 1) ++odd;
    }

    if(odd == 0) return 1;
    else if(odd == 2) return 2;
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
                    ++deg[i];
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
        st.push(u);
        int cur = u;

        vector<int> res;
        while(!st.empty()) {
            if(st.size() > 0) {
                cur = st.top();
            }

            bool hasEdge = false;
            for (int i = 1; i <= vertex; ++i) {
                if(arr[cur][i]) {
                    st.push(i);

                    // remove the edge from the graph
                    arr[cur][i] = 0;
                    arr[i][cur] = 0;

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