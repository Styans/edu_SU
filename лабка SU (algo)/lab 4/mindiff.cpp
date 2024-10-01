#include <iostream>
#include <climits>
using namespace std;

int *getNum(int &num);

struct result {
    int first;
    int last;
};

result finddiffs(int arr[], int num);

int main() {
    int num;
    int *arr = getNum(num);

    if (num > 100000) {
        cout << -1;
        return 0;
    }

    result res = finddiffs(arr, num);

    // Выводим индексы (1-based индексация)
    cout << res.first + 1 << " " << res.last + 1;

    delete[] arr;
    return 0;
}

result finddiffs(int arr[], int num) {
    int tempf = 0, temps = 0;
    long long min_diff = LLONG_MAX;
    result res;

    // Поиск минимальной разницы
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            long long diff = abs(arr[j] - arr[i]);
            if (diff < min_diff) {
                min_diff = diff;
                tempf = i;
                temps = j;
            }
            if (min_diff == 0) {
                break;
            }
        }
    }

    res.first = min(tempf, temps);
    res.last = max(tempf, temps);
    return res;
}

int *getNum(int &num) {
    cin >> num;
    int *s = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> s[i];
    }
    return s;
}
