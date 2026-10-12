# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Andhika Nur Pratama - 109082500056</p>

## Dasar Teori
<div align="justify">Abstract Data Type (ADT) adalah definisi statik yang terdiri dari sebuah tipe data dan sekumpulan primitif atau operasi dasar, serta dapat mengandung definisi ADT lain di dalamnya[cite: 1]. Dalam penerapannya, ADT diimplementasikan secara modular yang mencakup file spesifikasi header (`.h`) untuk mendefinisikan tipe dan purwarupa fungsi, file badan (`.cpp`) untuk realisasi kode program yang memanfaatkan konstruktor serta selektor, dan program utama (*driver*) untuk menjalankan alur logika program[cite: 1, 2, 3]. Pemisahan struktur ini bertujuan untuk menyembunyikan rincian implementasi internal sehingga program menjadi lebih terstruktur, modular, dan mudah dikembangkan.</div>

### A. Konsep Dasar Abstract Data Type (ADT)<br/>
...
#### 1. Definisi Tipe dan Primitif
#### 2. Struktur Modul ADT
#### 3. Keunggulan Penggunaan ADT

### B. Implementasi ADT dalam Bahasa Pemrograman C++<br/>
...
#### 1. File Header (.h)
#### 2. File Implementasi (.cpp)
#### 3. Program Utama (main.cpp)

## Guided 

### 1. Mahasiswa

```H
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m) ;
float rata2 (mahasiswa m) ;
#endif // MAHASISWA_H_INCLUDED
```
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs (mahasiswa &m) {
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input nilai = ";
    cin >> (m).nilai1;
    cout << "input nilai2 = ";
    cin >> (m).nilai2;
}

float rata2 (mahasiswa m) {
    return (m.nilai1+m.nilai2)/2;
}
```
```M
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main()
{
    mahasiswa mhs;
    inputMhs(mhs) ;
    cout << "rata-rata = " << rata2 (mhs) ;
    return 0;
}  
```
penjelasan singkat guided 1

### Unguided

### 1. (Data Mahasiswa)

```H
#ifndef MAHSISWA_H_INCLUDED
#define MAHSISWA_H_INCLUDED

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas;
    float nilaiAkhir;
};

void inputMhs(Mahasiswa &m);

float hitungNilaiAkhir(Mahasiswa &m);

void tampilMhs(Mahasiswa &m);

#endif
```
```C++
#include <iostream>
#include "dataMahasiswa.h"

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return uts * 0.3 + uas * 0.4 + tugas * 0.3;
}

void inputMhs(Mahasiswa &m) {
    cout << "Nama:          ";
    getline (cin >> ws, m.nama);
    cout << "NIM:           ";
    cin >> m.nim;
    cout << "UTS:           ";
    cin >> m.uts;
    cout << "UAS:           ";
    cin >> m.uas;
    cout << "Tugas:         ";
    cin >> m.tugas;
    m.nilaiAkhir = hitungNilaiAkhir(m.uts, m.uas, m.tugas);
}

void tampilMhs(Mahasiswa &m) {
    cout << "Nama:          " << m.nama << endl;
    cout << "NIM:           " << m.nim << endl;
    cout << "UTS:           " << m.uts << endl;
    cout << "UAS:           " << m.uas << endl;
    cout << "Tugas:         " << m.tugas << endl;
    cout << "Nilai Akhir:   " << m.nilaiAkhir << endl;
}

```
```C++
#include <iostream>
#include "dataMahasiswa.h"
using namespace std;

int main() {
    Mahasiswa dataMhs[10];
    int n;

    do {
        cout << "Jumlah mahasiswa (1-10): ";
        cin >> n;
    } while (n < 1 || n > 10);

    for (int i = 0; i < n; i++) {
        cout << "\n=== Data mahasiswa ke-" << i + 1 << " ===" << endl;
        inputMhs(dataMhs[i]);
    }

    cout << "\n===== DAFTAR MAHASISWA =====" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n--- Mahasiswa ke-" << i + 1 << " ---" << endl;
        tampilMhs(dataMhs[i]);
    }
    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/Hazell3/1090825000056_Andhika-Nur-Pratama_Smstr3/blob/main/Pertemuan3_Modul3/Unguided/Data_Mahasiswa/Output%20dataMahasiswa.png)

Program ini menyimpan data maksimal 10 mahasiswa. Struct mahasiswa berisi nama, nim, uts, uas, tugas, dan nilaiAkhir, lalu dipisah menjadi tiga file: mahasiswa.h untuk deklarasi, mahasiswa.cpp untuk isi fungsi, dan main.cpp sebagai program utama. Fungsi inputMhs membaca data dari keyboard dan langsung mengisi nilai akhir lewat hitungNilaiAkhir (rumus 0.3uts + 0.4uas + 0.3*tugas), sedangkan tampilMhs mencetak datanya. Di main, array dataMhs[10] diisi dan ditampilkan memakai perulangan for.

### 2. (Mata Pelajaran)

```H
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);

void tampil_pelajaran(pelajaran pel);

#endif
```
```C++
#include <iostream>
#include "mapel.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
```C++
#include <iostream>
#include "mapel.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/Hazell3/1090825000056_Andhika-Nur-Pratama_Smstr3/blob/main/Pertemuan3_Modul3/Unguided/Mata_Pelajaran/Output%20Mapel.png)

ADT pelajaran dibuat dari struct berisi namaMapel dan kodeMapel, lalu dipisah menjadi tiga file: mapel.h untuk type dan deklarasi fungsi, mapel.cpp untuk isi fungsi, dan main.cpp sebagai program utama. Fungsi create_pelajaran adalah konstruktor yang membuat variabel pelajaran dari nama dan kode yang diberikan, lalu mengembalikannya. Prosedur tampil_pelajaran mencetak isinya ke layar, sehingga main menampilkan “nama pelajaran : Struktur Data” dan “nilai : STD”.

### 3. (Fungsi & Procedure)

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[3][3] = {{11, 12, 13}, {14, 15, 16}, {17, 18, 19}};

    cout << "=== Array A (awal) ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B (awal) ===" << endl;
    tampilArray(B);

    int baris, kolom;
    cout << "\nMasukkan posisi yang ditukar (baris kolom, 0-2): ";
    cin >> baris >> kolom;
    if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
        cout << "Posisi tidak valid!" << endl;
        return 1;
    }
    tukarArray(A, B, baris, kolom);

    cout << "\n=== Array A (setelah tukar posisi [" << baris << "][" << kolom << "]) ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B (setelah tukar posisi [" << baris << "][" << kolom << "]) ===" << endl;
    tampilArray(B);

    int *ptr1 = &A[0][0];
    int *ptr2 = &B[2][2];

    cout << "\nSebelum tukar pointer : *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Sesudah tukar pointer : *ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;

    cout << "\n=== Array A (akhir) ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B (akhir) ===" << endl;
    tampilArray(B);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3](https://github.com/Hazell3/1090825000056_Andhika-Nur-Pratama_Smstr3/blob/main/Pertemuan3_Modul3/Unguided/Fungsi%20%26%20Procedure/Output%20Fungsi%26Procedure.png)

Program ini memakai dua array 2D berukuran 3x3 dan dua pointer integer. Fungsi tampilArray mencetak isi array dengan dua for bersarang, dan tukarArray menukar elemen A dan B pada posisi baris dan kolom yang dipilih lewat variabel sementara temp. Fungsi tukarPointer menukar isi dua variabel yang ditunjuk pointer, jadi elemen array aslinya ikut berubah karena pointer menyimpan alamatnya.

## Kesimpulan
Kesimpulan yang dapat diambil adalah bahwa Abstract Data Type (ADT) merupakan definisi statik yang terdiri dari tipe data dan sekumpulan operasi dasar (primitif) untuk menyarikan struktur data serta menyembunyikan rincian implementasi internal dari pengguna. Dalam penerapannya pada bahasa pemrograman seperti C++, ADT diimplementasikan secara modular melalui pemisahan file spesifikasi header (.h), file implementasi (.cpp), dan program utama (driver). Pemisahan struktur ini menjadikan kode program lebih terstruktur, mudah dipelihara, serta aman dari modifikasi langsung pada struktur data internalnya.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
