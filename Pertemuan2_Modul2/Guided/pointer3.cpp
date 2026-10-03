#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout << "Nilai angka            : " << angka << endl;
    cout << "Alamat angka           : " << &angka << endl;
    cout << "Isi Pointer            : " << pointer << endl;
    cout << "Nilai dari pointer     : " << *pointer << endl;

    return 0;
}