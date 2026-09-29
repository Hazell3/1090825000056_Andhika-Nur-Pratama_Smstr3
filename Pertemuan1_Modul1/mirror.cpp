#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "input: ";
    cin >> n;
    cout << "output:" << endl;

    for (int k = n; k >= 0; k--) {
        for (int s = 0; s < (n - k) * 2; s++)
            cout << " ";

        for (int i = k; i >= 1; i--)
            cout << i << " ";

        cout << "*";

        for (int i = 1; i <= k; i++)
            cout << " " << i;

        cout << endl;
    }

    return 0;
}