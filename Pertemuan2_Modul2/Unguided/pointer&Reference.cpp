#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z);
void tukarReference(int &x, int &y, int &z);

int main() {
    int a, b, c;

    // ===== Call by Pointer =====
    a = 4; b = 6; c = 8;
    cout << "=== Call by Pointer ===" << endl;
    cout << "kondisi sebelum ditukar \n";
    cout << " a = " << a << " b = " << b << " c = " << c << endl;

    tukarPointer(&a, &b, &c);

    cout << "kondisi setelah ditukar \n";
    cout << " a = " << a << " b = " << b << " c = " << c << endl;

    // ===== Call by Reference =====
    a = 4; b = 6; c = 8;
    cout << "\n=== Call by Reference ===" << endl;
    cout << "kondisi sebelum ditukar \n";
    cout << " a = " << a << " b = " << b << " c = " << c << endl;

    tukarReference(a, b, c);

    cout << "kondisi setelah ditukar \n";
    cout << " a = " << a << " b = " << b << " c = " << c << endl;

    return 0;
}

void tukarPointer(int *x, int *y, int *z) {
    int temp;
    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z) {
    int temp;
    temp = x;
    x = y;
    y = z;
    z = temp;
}