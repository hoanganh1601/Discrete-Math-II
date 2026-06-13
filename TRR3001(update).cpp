#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
using ll = long long;

int vertex, u;
int mtx[105][105];
vector<int> adj[105];
bool visited[105];
int deg[105];

void DFS(int u) {
    visited[u] = true;
    for (int x : adj[u]) {
        if(!visited[x]) DFS(x);
    }
}

bool lienThong() {
    memset(visited, false, sizeof(visited));
    int startNode = 1;
    for (int i = 1; i <= vertex; ++i) {
        if(deg[i] > 0) {
            startNode = i;
            break;
        }
    }

    DFS(startNode);

    for (int i = 1; i <= vertex; ++i) {
        if(deg[i] > 0 && !visited[i]) return false;
    }

    return true;
}

int isEuler() {
    if(!lienThong()) return 0;

    int odd = 0;
    for (int i = 1; i <= vertex; ++i) {
        if(deg[i] % 2 == 1) {
            ++odd;
        }
    }
    if(odd == 0) return 1;
    else if(odd == 2) return 2;
    else return 0; 
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
                cin >> mtx[i][j];
                if(mtx[i][j]) {
                    adj[i].push_back(j);
                    ++deg[i];       
                }
            }
        }

        cout << isEuler() << endl;
    }

    else {
        cin >> vertex >> u;
        set<int> ke[105];
        for (int i = 1; i <= vertex; ++i) {
            for (int j = 1; j <= vertex; ++j) {
                cin >> mtx[i][j];
                if(mtx[i][j]) ke[i].insert(j);
            }
        }

        vector<int> res;
        res.reserve(10005);

        stack<int> st;
        st.push(u);

        while(!st.empty()) {
            int cur = st.top(); 

            if(ke[cur].size() > 0) {
                int x = *ke[cur].begin();
                st.push(x);

                ke[cur].erase(x);
                ke[x].erase(cur);
            }

            else {
                res.push_back(cur);
                st.pop();
            }
        }

        reverse(res.begin(), res.end());
        for (int x : res) cout << x << " ";
    }

    return 0;
}