//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define op() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back

void BFS(ll n, ll s, ll des, vector<vector<ll>> &adj)
{
     vector<ll> level(n+1, -1);
     vector<ll> par(n+1, -1);
     level[s] = 0;
     queue<ll> q;
     q.push(s);
     while(!q.empty())
     {
         int u = q.front();
         q.pop();
         for(int v : adj[u]) {
            if(level[v] == -1) {
                level[v] = level[u] + 1;
                par[v] = u;
                q.push(v);
            }
         }
     }

     //for(int i=1; i<=n; i++) cout<<level[i]<<" "; cout<<endo;
     vector<ll> path;
     path.pb(des);
     while(par[des] != -1)
     {
         path.pb(par[des]);
         des = par[des];
     }

     if (level[des] == -1) {
        cout<<"No path exists from "<< s<<" to "<<des;
     }
     else {
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
    }
    cout << endl;
}
int main()
{
    ll n, e;
    cin>>n>>e;
    vector<vector<ll>> adj(n+1);
    for(int i=0; i<e; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);  //pb -> push_back
        adj[v].pb(u);
    }
    cout<<"source : ";
    int source; cin>>source;
    cout<<"Destination : ";
    int des; cin>>des;
    BFS(n, source, des, adj);
}
