#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i)
    {
        int x;
        cin >> x;

        int left = lower_bound(a.begin(), a.end(), x) - a.begin();
        int right = upper_bound(a.begin(), a.end(), x) - a.begin();
        cout << right - left << endl;
    }

    return 0;
}
