#include <iostream>
#include <algorithm>

using namespace std;

int *getNum(int& num, int& sum);
void quickSort(int arr[], int l, int r);

int main()
{
    int num, sum;
    int *arr = getNum(num, sum);
    quickSort(arr, 0, num-1);
    int count;
    for (int i = 0; i < num; i++)
    {
        if (sum >= arr[i]){
            sum -= arr[i];
            count++;
        }else {
            break;
        }
    }
    cout << count << endl;
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

int* getNum(int& num, int& sum)
{
    cin >> num >> sum;
    int *s = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> s[i];
    }

    return s;
}