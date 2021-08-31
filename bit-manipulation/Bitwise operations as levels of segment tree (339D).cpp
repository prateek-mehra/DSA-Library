#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long
#define pb push_back
#define mkp make_pair
#define ms(a) memset(a, 0, sizeof(a));
#define all(a) a.begin(), a.end()
#define endl '\n'
#define boost                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define mod 1000000007
#define inf 1e18
#define deb(x) cout << #x << " " << x << endl;
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define deb3(x, y, z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;

const int N = 2e5 + 5;
int a[N], t[4 * N];

void build(int v, int tl, int tr, int flag)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;

        build(v * 2, tl, tm, flag - 1);
        build(v * 2 + 1, tm + 1, tr, flag - 1);

        if (flag & 1)
        {
            t[v] = t[v * 2] | t[v * 2 + 1];
        }
        else
        {
            t[v] = t[v * 2] ^ t[v * 2 + 1];
        }
    }
}

void update(int v, int tl, int tr, int pos, int new_value, int flag)
{

    if (tl == tr)
    {
        t[v] = new_value;
    }
    else
    {
        int tm = (tl + tr) / 2;

        if (pos <= tm)
        {
            update(v * 2, tl, tm, pos, new_value, flag - 1);
        }
        else
        {
            update(v * 2 + 1, tm + 1, tr, pos, new_value, flag - 1);
        }

        if (flag & 1)
        {
            t[v] = t[v * 2] | t[v * 2 + 1];
        }
        else
        {
            t[v] = t[v * 2] ^ t[v * 2 + 1];
        }
    }
}

int query(int v, int tl, int tr, int l, int r, int flag)
{
    if (r < l)
        return 0;

    if (l == tl && r == tr)
    {
        return t[v];
    }

    int tm = (tl + tr) / 2;
    if (flag & 1)
    {
        return query(v * 2, tl, tm, l, min(r, tm), flag - 1) | query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, flag - 1);
    }
    else
    {
        return query(v * 2, tl, tm, l, min(r, tm), flag - 1) ^ query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, flag - 1);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < (1<<n); i++)
        cin >> a[i];

    build(1, 0, (1 << n) - 1, n);

    for (int i = 0; i < m; i++)
    {
        int p, b;
        cin >> p >> b;
        p--;
        update(1, 0, (1 << n) - 1, p, b, n);

        cout << query(1, 0, (1 << n) - 1, 0, (1 << n) - 1, n)<<endl;
    }
}

signed main()
{
    //boost
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int tt = 1;
    //cin >> tt;
    while (tt--)
        solve();
    return 0;
}
