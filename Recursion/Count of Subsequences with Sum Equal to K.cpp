//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

ll rec(ll in, vector<ll> v, ll n, ll k, ll sum)
{
    if(sum > k) return 0;
    if(in >= n) {
       if(sum == k) return 1;
       return false;
    }
    
    //take in,th index
    sum += v[in];
    ll l = rec(in+1, v, n, k, sum);
    
    //not take in,th index
    sum -= v[in];
    ll r = rec(in+1, v, n, k, sum);
    
    return l + r;
}
int main()
{
    ll i, j, x = 0, n, m, p = 0, k, t, q, a, y, b, c, z;
    cin>>n;
    vector<ll> v(n), vc;
    for(i=0; i<n; i++) cin>>v[i];
    cin>>k;
    cout<<rec(0, v, n, k, 0)<<endl;
 }
