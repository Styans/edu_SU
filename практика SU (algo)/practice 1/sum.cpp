#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long result = 0;  // Итоговая сумма
    long long current_sum = 0;  // Текущая сумма чисел от 1 до i

    for (int i = 1; i <= n; ++i) {
        current_sum += i;  // Накапливаем сумму чисел от 1 до i
        result += current_sum;  // Добавляем эту сумму к итоговому результату
    }

    cout << result << endl;  // Выводим результат
    return 0;
}
