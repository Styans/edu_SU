#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
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

         auto it = upper_bound(strings.begin(), strings.end(), query);

        if (it == strings.begin()) {
            cout << "NO" << endl; 
            
        } else {
             cout << *(it - 1) << endl;
        }
    }

    return 0;
}
