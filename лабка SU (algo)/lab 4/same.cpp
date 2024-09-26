#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> indices;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            indices.push_back(i+1);
        }
    }

    if (indices.empty()) {
        cout << -1 << endl;
    } else {
        for (int index : indices) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
