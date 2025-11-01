//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

void rec(ll in, vector<ll> v, vector<ll> vc, ll n, ll k, ll sum)
{
    if(in >= n) {
       if(sum == k) {
          for(auto u : vc) cout<<u<<" "; 
          cout<<endl;
       }
       return;
    }
    
    //take in,th index 
    vc.pb(v[in]);
    sum += v[in];
    rec(in+1, v, vc, n, k, sum);
    
    //not take in,th index
    vc.pop_back();
    sum -= v[in];
    rec(in+1, v, vc, n, k, sum);
}
int main()
{
    ll i, j, x = 0, n, m, p = 0, k, t, q, a, y, b, c, z;
    cin>>n;
    vector<ll> v(n), vc;
    for(i=0; i<n; i++) cin>>v[i];
    cin>>k;
    rec(0, v, vc, n, k, 0);
    
 }
