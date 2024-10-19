#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);  // Массив из n чисел
    for (int i = 0; i < n; ++i) {
        cin >> a[i];  // Вводим элементы массива
    }

    for (int i = 0; i < q; ++i) {  // Обрабатываем каждый запрос
        int x;
        cin >> x;  // Вводим число из запроса

        auto it = lower_bound(a.begin(), a.end(), x);  // Ищем позицию x или ближайшего большего элемента

        if (it == a.begin()) {  
            // Если x меньше или равен первому элементу массива
            cout << *it << endl;
        } else if (it == a.end()) {  
            // Если x больше всех элементов массива
            cout << *(it - 1) << endl;
        } else {  
            // Если нашли элемент посередине
            int upper = *it;       // Текущий элемент (ближайший больший или равный x)
            int lower = *(it - 1);  // Предыдущий элемент

            // Проверяем, какой элемент ближе к x
            if (x - lower <= upper - x) {
                cout << lower << endl;  // Выводим меньший при равенстве расстояний
            } else {
                cout << upper << endl;
            }
        }
    }

    return 0;
}
