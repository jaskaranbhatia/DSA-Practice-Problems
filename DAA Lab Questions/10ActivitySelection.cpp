#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second < p2.second;
}

int main()
{
    int n;
    cin >> n;
    vector< pair<int, int> > act(n);
    for (int i = 0; i < n; i++)
    {
        int st, ft;
        cin >> st >> ft;
        act[i] = make_pair(st, ft);
    }
    sort(act.begin(), act.end(), cmp);
    int ans = 1;
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (act[j].second <= act[i].first)
        {
            ans++;
            j = i;
        }
    }
    cout << ans << endl;
}