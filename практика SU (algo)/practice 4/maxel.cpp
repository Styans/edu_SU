#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_value = a[0];
    int max_index = 0;

    for (int i = 1; i < n; ++i) {
        if (a[i] > max_value) {
            max_value = a[i];
            max_index = i;
        }
    }

    cout << max_value << endl;
    cout << max_index + 1 << endl;  // Выводим индекс в формате 1-индексации

    return 0;
}
