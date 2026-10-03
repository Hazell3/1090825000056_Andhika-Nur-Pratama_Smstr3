# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Andhika Nur Pratama - 109082500056</p>

## Dasar Teori
Dasar teori Bahasa C++ mencakup pembahasan mengenai array yang terdiri dari array satu dimensi, dua dimensi, serta array berdimensi banyak untuk menyimpan kumpulan data dengan tipe seragam. Selain itu, dipelajari pula konsep pointer dan memori yang merepresentasikan alamat memori serta pemanfaatannya dalam mengakses elemen array maupun string. Modul ini juga membahas fungsi dan prosedur sebagai blok kode terstruktur untuk menjalankan tugas khusus—di mana prosedur tidak mengembalikan nilai balik—serta mekanisme pelewatan parameter fungsi (parameter passing) yang meliputi metode call by value, call by pointer, dan call by reference.

## Guided 

### 1. Array 1 Dimensi

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
Array nilai menyimpan 5 angka, lalu perulangan for mencetak semuanya dengan nomor urut 1 sampai 5.

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
Program ini membuat array 2 dimensi (3x3) berisi nilai lalu mencetaknya per baris, dan di akhir mencetak nilai[1][2] yaitu 88. Ada 2 error: nilai[i][i] harus nilai[i][j] (kalau tidak, hanya diagonal yang tercetak berulang), dan return 0 kurang titik koma menjadi return 0;

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
Program ini membuat array 3 dimensi berukuran 2x2x3 (2 blok, masing-masing 2 baris dan 3 kolom) berisi angka 10 sampai 120, lalu mencetak data[0][1][2], yaitu blok pertama, baris kedua, kolom ketiga, sehingga outputnya 60. Tidak ada error pada kode ini.

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
Program ini mencetak nilai angka (100), tetapi baris "Alamat angka" salah karena masih mencetak angka; seharusnya &angka agar yang tampil alamat memorinya.

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
Program ini mencetak arr[3] yaitu b, lalu &(arr[4]) yang bertipe char* sehingga dibaca sebagai string mulai dari d, tetapi array tidak punya '\0' di akhir, jadi hasilnya de diikuti karakter acak (perilaku tidak terdefinisi), bukan alamat memori.

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
Program ini membuat pointer pointer yang menyimpan alamat angka, lalu mencetak nilai angka (100), alamat angka dan isi pointer (keduanya sama, berupa alamat memori), serta *pointer yang mengambil nilai di alamat itu yaitu 100. Tidak ada error.

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
Program ini meminta tiga angka, lalu fungsi maks3 mencari yang terbesar dengan membandingkan b dan c satu per satu terhadap temp_max (awalnya a), dan hasilnya dicetak sebagai "Nilai maksimum". Tidak ada error.

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
Kedua program menukar isi a (4) dan b (6) lewat fungsi tukar, hasilnya sama: setelah ditukar a = 6 dan b = 4. Bedanya, call by reference memakai parameter int &x, int &y dan dipanggil tukar(a, b), sedangkan call by pointer memakai int *x, int *y, dipanggil tukar(&a, &b), dan isinya diakses dengan *x dan *y. Tidak ada error pada kedua kode.


## Unguided 

### 1. (Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3)

```C++
#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {27, 56, 30},
        {55, 21, 29},
        {75, 90, 42}
    };

    int nilai2[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int hasil[3][3];

    cout << "Hasil Penjumlahan:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = nilai[i][j] + nilai2[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = nilai[i][j] - nilai2[i][j];
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                hasil[i][j] = hasil[i][j] + nilai[i][k] * nilai2[k][j];
            }
            cout << hasil[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/Hazell3/1090825000056_Andhika-Nur-Pratama_Smstr3/blob/main/Pertemuan2_Modul2/Unguided/Output%20Matriks.png)

Dua matriks 3x3 dijumlah, dikurang, dan dikali pakai loop bersarang. Hasilnya langsung ditampilkan.

### 2. (Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel)

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/Hazell3/1090825000056_Andhika-Nur-Pratama_Smstr3/blob/main/Pertemuan2_Modul2/Unguided/Output%20Pointer%26Reference.png)

Dua fungsi, pointer dan reference, menukar 3 variabel secara bergeser (a ← b, b ← c, c ← a) pakai temp.

### 3. (Diketahui sebuah array 1 dimensi sebagai berikut :  arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : --- Menu Program Array ---  • Tampilkan isi array  • cari nilai maksimum • cari nilai minimum  • Hitung nilai rata - rata )

```C++
#include <iostream>
using namespace std;

int cariMinimum(int arrA[]) {
    int min = arrA[0];
    for (int i = 1; i < 10; i++) {
        if (arrA[i] < min) {
            min = arrA[i];
        }
    }
    return min;
}

int cariMaksimum(int arrA[]) {
    int max = arrA[0];
    for (int i = 1; i < 10; i++) {
        if (arrA[i] > max) {
            max = arrA[i];
        }
    }
    return max;
}

void hitungRataRata(int arrA[]) {
    int total = 0;
    for (int i = 0; i < 10; i++) {
        total = total + arrA[i];
    }
    cout << "Nilai rata-rata = " << total / 10.0 << endl;
}

int main() {
    int arrA[10];

    arrA[0] = 11;
    arrA[1] = 8;
    arrA[2] = 5;
    arrA[3] = 7;
    arrA[4] = 12;
    arrA[5] = 26;
    arrA[6] = 3;
    arrA[7] = 54;
    arrA[8] = 33;
    arrA[9] = 55;

    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                for (int i = 0; i < 10; i++) {
                    cout << "Data ke-" << i + 1 << " = "
                    << arrA[i] << endl;
                }
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(arrA) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(arrA) << endl;
                break;
            case 4:
                hitungRataRata(arrA);
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3]!(https://github.com/Hazell3/1090825000056_Andhika-Nur-Pratama_Smstr3/blob/main/Pertemuan2_Modul2/Unguided/Output%20Array%201%20Dimensi.png)

Array 10 angka. Fungsi mencari min dan max, prosedur menghitung rata-rata, dan menunya pakai *switch-case*.

## Kesimpulan
Dari ketiga soal Modul 2 dapat disimpulkan bahwa array 2D cocok untuk data berbentuk tabel seperti matriks, sedangkan array 1D cocok untuk data berderet, dan keduanya diakses lewat indeks yang dimulai dari 0, biasanya dengan for. Pointer dan reference sama-sama bisa mengubah nilai variabel asli dari dalam fungsi, berbeda dengan call by value yang hanya menyalin nilai. Pointer memakai alamat (& saat memanggil dan * saat mengakses), sedangkan reference lebih singkat karena variabelnya langsung dipakai. Fungsi mengembalikan nilai lewat return, sedangkan prosedur (void) tidak, dan keduanya membuat program lebih terstruktur serta tidak berulang.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
