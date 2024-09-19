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
    // int arr[n];
    if (n > 100000)
    {
        return 0;
    }
    int num = 0;
    int sum = 0;
    // if (n < 0)
    // {
    //     for (int i = 0; i >= n; i--)
    //     {
    //         num += i - 1;
    //         // cout << num << " num\n";
    //         sum += num;
    //         // cout << i << " num\n";
    //     }
    //     // return 0;
    // }
    // else
    // {
    for (int i = 1; i <= n; i++)
    {
        num += i;
        cout << num << " num\n";
        sum += num;
    }

    // cout << num << "\n";
    // }
    // for (int i = 0; i < n; i++) {
    cout << sum;
    //     cin >> a[i];
    // }

    return 0;
}
