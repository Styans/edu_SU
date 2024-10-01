#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << (r - l + 1) << endl;
    for (int i = l - 1; i < r; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
