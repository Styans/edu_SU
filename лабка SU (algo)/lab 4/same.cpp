#include <iostream>
#include <iostream>
#include <algorithm>

using namespace std;

int *getNum(int &num);
void quickSort(int arr[], int l, int r);

int main()
{
    int num;
    // cout << "num: " << num << endl;
    // cout << "num: " << arr << endl;
    cin >> num;
    if (num <= 0)
    {

        cout << -1 << endl;
        // cout << -1 << " " << -1 << "\n";
        return 0;
    }
    if (num == 0)
    {
        cout << 0 << endl;
        // cout << 0 << " " << 0 << "\n";
        return 0;
    }

    int *arr = getNum(num);
    int max_n = 1, max_s = 0, max_e = 0;
    int temp_n = 1, temp_s = 0;
    for (int i = 1; i < num; i++)
    {
        if (arr[i] < 0)
        {

            cout << -1 << endl;
            // cout << -1 << " " << -1 << "\n";
            return 0;
        }
        if (arr[i] == 0)
        {
            cout << 0 <<endl;
            // cout << 0 << " " << 0 << "\n";
            return 0;
        }
        if (arr[i] == arr[i - 1])
        {
            temp_n++;
        }
        else
        {
            if (temp_n > max_n)
            {
                max_n = temp_n;
                max_s = temp_s;
                max_e = i - 1;
            }
            temp_n = 1;
            temp_s = i;
        }
    }

    if (temp_n > max_n)
    {
        max_n = temp_n;
        max_s = temp_s;
        max_e = num - 1;
    }

    cout << max_n << "\n";
    cout << max_s + 1 << " " << max_e + 1 << "\n";
    delete[] arr;
    return 0;
}

void quickSort(int arr[], int l, int r)
{
    if (l > r)
        return;

    int p = arr[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (arr[i] < p)
            i++;
        while (arr[j] > p)
            j--;
        if (i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    quickSort(arr, l, j);
    quickSort(arr, i, r);
}

int *getNum(int &num)
{
    // cin >> num;
    int *s = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> s[i];
    }

    return s;
}