# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Andhika Nur Pratama - 109082500056</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
<div align="justify">Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.</div>

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
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

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
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

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
