// Set bit in a mask signifies that a candidate can be removed in order to let candidate k be the winner

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << " " << x << endl;
#define deb2(x, y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define deb3(x, y, z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;

int n, m, k;

int a[111][22];

int was[22];

int getWinner(int mask)
{
    for (int i = 0; i < m; i++)
    {
        was[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int v = 0;
        while ((mask >> a[i][v]) & 1)
            v++;

        was[a[i][v]]++;
    }

    pair<int, int> ans = {-1, -1};

    for (int i = 0; i < m; i++)
    {
        ans = max(ans, make_pair(was[i], -i));
    }

    return -ans.second;
}

int main()
{

    cin >> n >> m >> k;

    k--;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            a[i][j]--;
        }
    }

    int need = 22;

    for (int mask = 0; mask < (1 << m); mask++)
    {
        int cc = __builtin_popcount(mask);

        if (cc >= need)
            continue;

        if ((mask >> k) & 1)
            continue;

        if (getWinner(mask) == k)
        {
            need = min(need, cc);
        }
    }

    cout << getWinner(0) + 1 << endl;
    cout << need << endl;

    // Write your code here
}
