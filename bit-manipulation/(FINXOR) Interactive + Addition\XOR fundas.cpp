/*
Fundas used:
for a XOR of list like: SUM=a1XORa2XOR..an
XOR for each bit has to be focussed on individually
the sum: a1+a2+..an will reveal rightmost bit of SUM
a1XOR0+a2XOR0..+anXOR0=a1+a2+..an (no. remains same on XOR with 0)
XOR with 1 causes a bit to flip
contribution of ith bit is 2^i
so for n set ith bits it is n*2^i
also, m unset ith bits can contribute if they are flipped individually by doing aiXORk
the contribution difference is found out and finally no. of set ith bits in summation operands
tell us if ith bit is set in ans or not
because XOR of odd no. of 1s is 1.
assert can be used at last to complete interactivity in terms of terminating in case of WA

x+y=n
(x-y)*2^i=S-S'
X and finally parity of x is found out using above eqns.
*/

#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
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

void solve()
{
    int n;
    cin >> n;

    cout << "1"
         << " "
         << "1048576" << endl;

    int sum;
    cin >> sum;

    int ans1 = 0;

    sum -= n * (1LL << 20);

    if (sum % 2 == 1)
        ans1 += 1;

    for (int i = 1; i <= 19; i++)
    {
        cout << "1"
             << " " << (1 << i) << endl;

        int sum1;
        cin >> sum1;

        int diff = (sum - sum1) / (1LL << i);

        int on = (diff + n) / 2;

        if (on % 2 == 1)
            ans1 |= (1LL << i);
    }

    cout << "2"
         << " " << ans1 << endl;

    int x;
    cin >> x;

    assert(x == 1);
}

signed main()
{
    //boost
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
