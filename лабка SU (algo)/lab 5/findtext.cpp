#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(const vector<string>& strings, const string& query) {
    int low = 0, high = strings.size() - 1, best = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (strings[mid] <= query) {
            best = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }

    sort(strings.begin(), strings.end());

    cin >> m;
    for (int i = 0; i < m; ++i) {
        string query;
        cin >> query;

        int idx = binary_search(strings, query);
        if (idx == -1) {
            cout << "NO" << endl;
        } else {
            cout << strings[idx] << endl;
        }
    }

    return 0;
}
