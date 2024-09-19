#include <iostream>

using namespace std;

// Функция для сортировки массива по убыванию (используем пузырьковую сортировку)
void bubbleSortDescending(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // Меняем местами, если следующий элемент больше
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, w;
    cin >> n >> w; // Вводим количество предметов и максимальное количество предметов для выбора
    
    int a[n]; // Массив для стоимостей предметов (n <= 1000)

    // Вводим стоимости предметов
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Сортируем массив по убыванию стоимости с помощью пузырьковой сортировки
    bubbleSortDescending(a, n);

    // Считаем максимальную суммарную стоимость первых w предметов
    int max_sum = 0;
    if (n < w)
    {
        for (int i = 0; i < n; i++)
        {
            max_sum += a[i];
        }
    }
    else
    {
        for (int i = 0; i < w; i++)
        {

            max_sum += a[i];
        }
    }

    // Выводим максимальную суммарную стоимость
    // if (max_sum <= 0)
    // {
    //     cout << 0;
    //     return 0;
    // }
    // if (n <= 0)
    // {
    //     cout << 0;
    //     return 0;
    // }
    cout << max_sum;

    return 0;
}
