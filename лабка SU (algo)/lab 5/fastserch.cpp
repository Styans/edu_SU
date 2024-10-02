#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());

    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int l, r;
        cin >> l >> r;
        
        int left = lower_bound(a.begin(), a.end(), l) - a.begin();
        int right = upper_bound(a.begin(), a.end(), r) - a.begin();
        
        cout << right - left << endl;
    }

    return 0;
}
