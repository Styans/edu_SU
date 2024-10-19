#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);  // Создаем массив размера n
    for (int i = 0; i < n; ++i) {
        cin >> a[i];  // Вводим элементы массива
    }

    for (int i = 0; i < q; ++i) {  // Обрабатываем каждый запрос
        int x;
        cin >> x;  // Вводим число x из запроса

        auto lower = lower_bound(a.begin(), a.end(), x);  // Находим первое вхождение числа x
        auto upper = upper_bound(a.begin(), a.end(), x) - 1;  // Находим последнее вхождение числа x

        if (lower == a.end() || *lower != x) {  // Если число не найдено
            cout << 0 << endl;
        } else {  // Если число найдено
            cout << (lower - a.begin() + 1) << " " << (upper - a.begin() + 1) << endl;
        }
    }

    return 0;
}
