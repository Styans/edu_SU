#include <iostream>
#include <iostream>
#include <algorithm>

using namespace std;

int *getNum(int& num);
void quickSort(int arr[], int l, int r);

int main()
{
    int num;
    int *arr = getNum(num);
    quickSort(arr, 0, num-1);
    int counter;
    for (int i = 0; i < num; i++){
        if (arr[i] == arr[i+1]){
            counter++;
        }
    }
    cout << num-counter;
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

int* getNum(int& num)
{
    cin >> num;
    int *s = new int[num];
    for (int i = 0; i < num; i++)
    {
        cin >> s[i];
    }

    return s;
}