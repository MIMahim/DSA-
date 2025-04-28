//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define op() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pi 3.1415926536
#define pb push_back
#define all(v)((v).begin()), ((v).end())
#define endo '\n'
#define F first
#define S second
#define mp(x, y) make_pair(x, y)
#define gcd(a, b) __gcd(a, b);
#define lcm(a, b)(a * b) / gcd(a, b)
#define sizeofBit(n)(int) log2(n) + 1
#define Kth_bit(n, k)(n >> k & 1);
/*
bool prime(ll n) {if(n<2) return 0; for(ll i=2;i<=sqrt(n);i++){if(n%i==0)return 0;} return 1;}
ll power(ll a,ll b){if(b==0)return 1LL;if(b&1)return a*power(a,b-1);else{ll x=power(a,b/2);return x*x;}}
ll cntdigit(ll n) { string s=to_string(n); return s.size(); }
*/

ll BFS(ll c, ll n, ll s, ll des, vector<vector<vector<ll>>> &adj)
{
     vector<ll> level(n+1, -1);
     level[s] = 0;
     queue<ll> q;
     q.push(s);
     while(!q.empty())
     {
         int u = q.front();
         q.pop();
         for(int v : adj[c][u]) {
            if(level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
         }
     }

     //for(int i=1; i<=n; i++) cout<<level[i]<<" "; cout<<endo;
     return (level[des] != -1);
}
int main()
{
    ll i,j,x=0,n,m,p=0,k,t,q,a,y,b,z,e;
    cin>>n>>e;
    
    ll maxColor = 0;
    vector<tuple<ll,ll,ll>> edges;

    for(int i = 0; i < e; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        edges.pb({u, v, c});
        maxColor = max(maxColor, c);
    }
    
    vector<vector<vector<ll>>> adj(e + 1, vector<vector<ll>>(n + 1));
    for(auto [u, v, c] : edges) {
        adj[c][u].pb(v);
        adj[c][v].pb(u);
    }
    
    cin>>q;
    while(q--) 
    {
        cin>>a>>b;
        ll ans = 0;
        for(i=1; i<=e; i++) {
           if (!adj[i].empty()) {
             if(BFS(i, n, a, b, adj) == 1) ans++;
           }
        }
        cout<<ans<<endo;
    }
}
