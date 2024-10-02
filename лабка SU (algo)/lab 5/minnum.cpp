#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    vector<int> b(m);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    
    for (int i = 0; i < m; ++i) {
        int count = upper_bound(a.begin(), a.end(), b[i] - 1) - a.begin();
        cout << count << " ";
    }
    
    cout << endl;
    
    return 0;
}
