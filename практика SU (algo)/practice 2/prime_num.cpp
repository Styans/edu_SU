#include <iostream>
#include <cmath>
 
using namespace std;
 
int main()
{
 
    int n;
    int count;
    cin >> n;
    
    for (int i = 1; i <= sqrt(n) ; i++)
    {
        if (n % i == 0)
        {
            if (i == n/i) {
                count++;
            }wlse {
                count += 2
            }
        }
    }
    cout << count;
    return 0;
}