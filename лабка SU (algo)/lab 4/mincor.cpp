#include <iostream>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int *getNum(int &num);
void quickSort(int copyarr[], int l, int r);
float calculateDistance(int x1, int y1, int x2, int y2);

int main()
{
    int num;
    float min = 100000.0, distance;
    int x1, y1, x2, y2;
    cin >> num;
    if (num <= 0) {
        cout << "0 0";
        return 0;
    }
    // int *s = new int[num];
    for (int i = 0; i < num; i++)
    {

        cin >> x1 >> y1;

        distance = calculateDistance(x1, y1, 0, 0);
        if (distance < min)
        {
            min = distance;
            // cout << distance << " distance\n" << distance ;
            x2 = x1;
            y2 = y1;
            // cout << x1 << " " << y1 << "\n";
        }
    }
    cout << x2 << " " << y2;
    // delete[] arr;
    return 0;
}

float calculateDistance(int x1, int y1, int x2, int y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
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