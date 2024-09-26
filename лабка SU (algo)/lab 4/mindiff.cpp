#include <iostream>
#include <iostream>
#include <algorithm>

using namespace std;

int *getNum(int &num);
void quickSort(int copyarr[], int l, int r);

int main()
{
    int num;
    int *arr = getNum(num);
    int *copyarr = new int[num];

    for (int i = 0; i < num; i++)
    {
        copyarr[i] = arr[i];
    }

    int counter;
    int max = 0;
    int f, s;
    int min = 10000000;
    if (num > 100000)
    {
        cout << -1;
        return 0;
    }
    quickSort(copyarr, 0, num - 1);
    int tempdiffs = 100001;
    int tempf;
    int temps;
    for (int i = 0; i < num; i++)
    {
        if (copyarr[i + 1] - copyarr[i] < tempdiffs && copyarr[i + 1] - copyarr[i] >= 0)
        {
            tempdiffs = copyarr[i + 1] - copyarr[i];
            tempf = copyarr[i];
            temps = copyarr[i + 1];
        }
    }

    for (int i = 0; i < num; i++)
    {
        if (arr[i] == tempf)
        {
            f = i;
            break;
        }
    }

    // for (int i = 0; i < num; i++){
    //     cout << copyarr[i] << " ";
    // }
    for (int i = f-1; i < num; i++)
    {
        // cout << arr[i] << " ni\n";
        // cout << arr[i] << " ni\n";

        if (arr[i] == temps)
        {
            s = i;
            // cout << arr[i] << " \n";
            break;
        }   
    }
    // cout << temps << " \n";
    // cout << f << " first \n";
    // cout << s << " scond \n";
    cout << f + 1 << " " << s + 1;
    delete[] arr;
    return 0;
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

int *getNum(int &num)
{
    cin >> num;
    int *s = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> s[i];
    }

    return s;
}