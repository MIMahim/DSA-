#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define F first
#define S second
#define ll long long

ll n, m;
char mat[100][100];
int level[100][100];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(pair<int, int> u)
{
    if (u.F < 0 || u.F >= n || u.S < 0 || u.S >= m || mat[u.F][u.S] == '#')
        return false;
    return true;
}

void bfs(pair<int, int> s)
{
    queue<pair<int, int>> q;
    q.push(s);
    level[s.F][s.S] = 0;

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();

        pair<int, int> v;
        for (int i = 0; i < 4; i++)
        {
            v = {u.F + dx[i], u.S + dy[i]};
            if (isValid(v) && level[v.F][v.S] == -1)
            {
                q.push(v);
                level[v.F][v.S] = level[u.F][u.S] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    vector<pair<int, int>> p;
    memset(level, -1, sizeof(level));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    int a, b;
    cin>>a>>b; /// source
    p.pb({a, b});

    bfs(p[0]);

        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(level[i][j] == -1) total--;
            }
        }
        */
    int c, d;
    cin>>c>>d; ///destination

    cout<<level[c][d];
}

