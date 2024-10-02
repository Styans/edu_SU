#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Функция для вычисления суммы цифр числа
int sum_of_digits(const string &num) {
    int sum = 0;
    for (char c : num) {
        sum += c - '0';
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    set<int> sum_set;
    for (int i = 0; i < n; ++i) {
        string num;
        cin >> num;
        int sum = sum_of_digits(num);
        sum_set.insert(sum);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int s;
        cin >> s;
        if (sum_set.find(s) != sum_set.end()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
