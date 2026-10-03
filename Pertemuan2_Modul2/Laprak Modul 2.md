# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Andhika Nur Pratama - 109082500056</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 75;
    nilai[2] = 90;
    nilai[3] = 85;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << " = "
             << nilai[i] << endl;
    }

    return 0
}
```
penjelasan singkat guided 1

### 2. Array 2 Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85}
    };
    //print array 2 dimensi
    for (int i = 0; i < 3; i++ ) {
        for (int j = 0; j < 3; j++) {
            cout << nilai[i][i] << " "; 
        }

        cout << endl;
    }
    cout << endl;
    cout << nilai[1][2] << endl; //88
    return 0
}
```
penjelasan singkat guided 2

### 3. Array 3 Dimensi

```C++
#include <iostream>
using namespace std;

int main() {
    int data[2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60}
        },
        {
            {70, 80, 90},
            {100, 110, 120}
        }
    };
    cout << data[0][1][2] << endl; // 60

    return 0;
}
```
penjelasan singkat guided 3

### 4. Pointer 1

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    cout << "Nilai angka : " << angka << endl;
    cout << "Alamat angka : " << angka << endl;

    return 0;
}
```
penjelasan singkat guided 4

### 5. Pointer 2

```C++
#include <iostream>
using namespace std;

int main() {
    char arr[6];
    
    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'b';
    arr[4] = 'd';
    arr[5] = 'e';

    cout << arr[3] << endl;
    cout << &(arr[4]) << endl;

    return 0;
}
```
penjelasan singkat guided 5

### 6. Pointer 3

```C++
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
```
penjelasan singkat guided 6

### 7. Function

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c) {
    int temp_max = a;

    if (b > temp_max)
        temp_max = b;
    
    if (c > temp_max)
        temp_max = c;

    return temp_max;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai 1: ";
    cin >> x;

    cout << "Masukkan nilai 2: ";
    cin >> y;

    cout << "Masukkan nilai 3: ";
    cin >> z;

    cout << "Nilai maksimum = "
         << maks3(x, y, z) << endl;

    return 0;
}
```
penjelasan singkat guided 7

### 8. Procedure 

```C++
#include <iostream>
using namespace std;

void sapa() {
    cout << "Selamat datang di praktikum struktur data" << endl;
}

int main() {
    sapa();
    return 0;
}
```
penjelasan singkat guided 8

### 9. Call By Value

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(a, b);

    cout << "\nSetelah ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
```

### Call By Pointer 

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(&a, &b);

    cout << "\nSetelah ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
```
penjelasan singkat guided 8


## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
