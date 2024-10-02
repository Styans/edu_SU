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

    // Сортируем строки
    sort(strings.begin(), strings.end());

    cin >> m;
    for (int i = 0; i < m; ++i) {
        string query;
        cin >> query;

        // Используем бинарный поиск для нахождения позиции верхней границы
        auto it = upper_bound(strings.begin(), strings.end(), query);

        // Проверяем, есть ли строка меньше или равная query
        if (it == strings.begin()) {
            cout << "NO" << endl;
        } else {
            --it;
            cout << *it << endl;
        }
    }

    return 0;
}
