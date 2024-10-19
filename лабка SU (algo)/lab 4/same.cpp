#include <iostream>
#include <vector>
#include <algorithm>  // Для sort
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);  // Массив пар

    // Ввод массива пар
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    // Сортировка массива пар
    sort(a.begin(), a.end());

    // Вывод отсортированного массива
    for (const auto& p : a) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
