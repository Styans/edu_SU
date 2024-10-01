#include <iostream>
#include <iostream>
#include <algorithm>

using namespace std;

int getNum(int &num);
void quickSort(int copyarr[], int l, int r);

struct result
{
    int first;
    int last;
};

result finddiffs(int copyarr[], int arr[], int next, int num);
int main()
{
    int num;
    int arr = getNum(num);
    int copyarr = new int[num];

    for (int i = 0; i < num; i++)
    {
        copyarr[i] = arr[i];
    }

    int counter;
    int max = 0;
    long long min = 100000;
    if (num > 100000)
    {
        cout << -1;
        return 0;
    }
    quickSort(copyarr, 0, num - 1);

    result res = finddiffs(copyarr, arr, 0, num);

    cout << res.first + 1 << " " << res.last + 1;
    delete[] arr;
    return 0;
}

result finddiffs(int copyarr[], int arr[], int next, int num)
{
    // int f, s;
    int tempf;
    int temps;

    long long tempdiffs = LLONG_MAX;
    // int counter = 0;
    result res;
    if (next == num)
    {
        res.first = 0;
        res.last = 0;
        return res;
    }
    for (int i = next; i < num; i++)
    {
        if (copyarr[i + 1] - copyarr[i] < tempdiffs && copyarr[i + 1] - copyarr[i] >= 0)
        {
            tempdiffs = copyarr[i + 1] - copyarr[i];
            tempf = copyarr[i];
            temps = copyarr[i + 1];
            // cout << next << " next before\n";

            next = i;
            // cout << next << " next\n";
            // counter++;
        }
    }

    for (int i = 0; i < num; i++)
    {

        if (arr[i] == tempf)
        {
            res.first = i;
            break;
        }
    }

    // for (int i = 0; i < num; i++)
    // {
    //     cout << copyarr[i] << " ";
    // }
    // cout << " arr\n";

    for (int i = res.first + 1; i < num; i++)
    {
        if (arr[i] == temps)
        {
            res.last = i;
            break;
        }
    }

    // cout << res.first << " " << res.last << " wtf\n";
    if (res.last == 0 || res.last+1 == num)
    {
        res.first = 0;
        res.last = 0;
        return res;
    }
    if (res.first > res.last)
    {
        // cout << res.first << " " << res.last << " wtf\n";

        return finddiffs(copyarr, arr, next + 1, num);
    }
    return res;
}

void quickSort(int copyarr[], int l, int r)
{
    if (l > r)
        return;

    int p = copyarr[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (copyarr[i] < p)
            i++;
        while (copyarr[j] > p)
            j--;
        if (i <= j)
        {
            int tmp = copyarr[i];
            copyarr[i] = copyarr[j];
            copyarr[j] = tmp;
            i++;
            j--;
        }
    }
    quickSort(copyarr, l, j);
    quickSort(copyarr, i, r);
}

int getNum(int num)
{
    cin >> num;
    int *s = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> s[i];
    }

    return s;
}