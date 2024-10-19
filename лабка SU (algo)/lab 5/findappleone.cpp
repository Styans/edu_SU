#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> a(n), prefix_sum(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefix_sum[i] = a[i] + (i > 0 ? prefix_sum[i - 1] : 0);
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int q;
        cin >> q;
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (q <= prefix_sum[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << low + 1 << endl;
    }

    return 0;
}
