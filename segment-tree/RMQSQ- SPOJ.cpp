#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define endl '\n'
#define boost                    \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define mod 1000000007
#define inf 1e18
#define pf push_front
#define pob pop_back
#define pof pop_front
#define deb(x) cout << #x << " " << x << endl;
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define deb3(x, y, z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;

typedef pair<int, int> pi;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const int N = 1e5+10;
int st[4 * N];
int a[N];
void build(int v, int stl, int str)
{
    if (stl == str)
    {
        st[v] = a[stl];
    }
    else
    {
        int stm = (stl + str) / 2;
        build(v * 2, stl, stm);
        build(v * 2 + 1, stm + 1, str);
        st[v] = min(st[v * 2],st[v * 2 + 1]);
    }
}
int query(int v, int stl, int str, int l, int r)
{
    //deb(v);
    //deb2(stl,str);
    if (l > r)
        return INT_MAX;
    if (l == stl && r == str)
        return st[v];

    int stm = (stl + str) / 2;
    return min(query(v * 2, stl, stm, l, min(r, stm)),query(v * 2 + 1, stm + 1, str, max(l, stm + 1), r));
}

void update(int v, int stl, int str, int pos, int val)
{
    if (stl == str)
    {
        st[v] = val;
    }
    else
    {
        int stm = (str + stl) / 2;
        if (pos <= stm)
        {
            update(v * 2, stl, stm, pos, val);
        }
        else
        {
            update(v * 2 + 1, stm + 1, str, pos, val);
        }

        st[v] = min(st[v * 2],st[v * 2 + 1]);
    }
}
int32_t main()
{
    // boost
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        build(1, 0, n - 1);
        //for(int i=0;i<4*n;i++)
        //cout<<st[i]<<" ";
       
        int q;
        cin >> q;
        while (q--)
        {
            int l,r;
            cin>>l>>r;
            cout<<query(1,0,n-1,l,r)<<endl;
        }
    }
}
