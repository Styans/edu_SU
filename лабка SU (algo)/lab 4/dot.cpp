#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n; 

    int closest_x = 0;
    int closest_y = 0;
    long long min_distance_squared = LLONG_MAX; 

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y; 

        
        long long distance_squared = static_cast<long long>(x) * x + static_cast<long long>(y) * y;

       
        if (distance_squared < min_distance_squared) {
            min_distance_squared = distance_squared;
            closest_x = x;
            closest_y = y;
        }
    }

   
    cout << closest_x << " " << closest_y << endl;

    return 0;
}