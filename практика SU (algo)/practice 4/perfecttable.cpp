#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> table[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            if (table[i][j] == table[i][j + 1] &&
                table[i][j] == table[i + 1][j] &&
                table[i][j] == table[i + 1][j + 1]) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
