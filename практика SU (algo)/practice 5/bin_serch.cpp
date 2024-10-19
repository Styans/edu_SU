#include <iostream>
#include <vector>
#include <algorithm>  // Для функции binary_search
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;  // Вводим n (размер массива) и q (количество запросов)

    vector<int> a(n);  // Создаем вектор размера n для хранения элементов массива
    for (int i = 0; i < n; ++i) {
        cin >> a[i];  // Заполняем массив числами
    }

    for (int i = 0; i < q; ++i) {  // Обрабатываем каждый запрос
        int x;
        cin >> x;  // Вводим число, которое нужно найти
        if (binary_search(a.begin(), a.end(), x)) {  // Проверяем, есть ли x в массиве
            cout << "YES" << endl;  // Если есть, выводим "YES"
        } else {
            cout << "NO" << endl;  // Если нет, выводим "NO"
        }
    }

    return 0;
}