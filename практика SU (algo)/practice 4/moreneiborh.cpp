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

    // Поиск индекса элемента, который больше своих соседей
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            cout << i + 1 << endl; // Выводим в формате 1-индексации
            return 0;
        }
    }

    // Если таких элементов нет, выводим -1
    cout << -1 << endl;
    return 0;
}
