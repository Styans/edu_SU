#include <iostream>
#include <algorithm>

using namespace std;

// Функция для сложения двух чисел
int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count;
    int temp;
    for (int i = 0; i < n; i++) {
        if (arr[i] !=  arr[i + 1]) {
            count++;
            cout << count << " count\n";
        }else {
            if (temp >= count) {
                temp = count;
            cout << temp << " temp\n";

            }
            count = 0;
        }
    }
    cout <<temp;
    return 0;
}
