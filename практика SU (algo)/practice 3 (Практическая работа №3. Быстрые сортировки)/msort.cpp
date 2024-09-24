#include <iostream>
#include <algorithm>

using namespace std;

int *getNum(int& num);
void mergeSort()

int main()
{
    int num;
    int *arr = getNum(num);
    quickSort(arr, 0, num-1);
    for (int i = 0; i < num; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
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