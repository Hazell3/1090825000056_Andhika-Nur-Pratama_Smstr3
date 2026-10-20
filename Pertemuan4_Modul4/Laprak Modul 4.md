# <h1 align="center">Laporan Praktikum Modul 4 - LINKED LIST</h1>
<p align="center">Andhika Nur Pratama - 109082500056</p>

## Dasar Teori
<div align ="justify">Linked List atau senarai berantai merupakan salah satu bentuk struktur data linear yang terdiri dari kumpulan elemen atau node yang saling terhubung menggunakan pointer. Setiap node menyimpan data dan alamat node berikutnya sehingga membentuk suatu rangkaian data yang dinamis. Berbeda dengan array, Linked List tidak memerlukan penyimpanan elemen secara berurutan di dalam memori. Struktur data ini memiliki beberapa jenis, yaitu Singly Linked List, Doubly Linked List, dan Circular Linked List. Operasi yang dapat dilakukan pada Linked List meliputi penambahan, penghapusan, pencarian, dan penelusuran data. Linked List memiliki kelebihan berupa fleksibilitas dalam pengelolaan data, tetapi membutuhkan memori tambahan untuk menyimpan pointer. Oleh karena itu, Linked List banyak digunakan dalam pengembangan berbagai struktur data dan aplikasi komputer yang membutuhkan pengelolaan data secara dinamis.<div/>

### A. Konsep Dasar Linked List<br/>

#### 1. Definisi
#### 2. Alasan Menggunakan Pointer
#### 3. Model ADT Linked List

### B. Karakteristik Singly Linked List<br/>
#### 1. Hanya memiliki satu arah pointer.
#### 2. Memerlukan satu buah pointer utama (first/head) yang menunjuk ke alamat elemen pertama.
#### 3. Node atau simpul terakhir menunjuk ke nilai NULL (kecuali pada list circular).
#### 4. Pembacaan data hanya dapat dilakukan secara maju (forward).
#### 5. Komponen dalam setiap elemen terdiri dari Data (informasi utama) dan Successor (next, penunjuk alamat elemen di         depannya).

### C. Manajemen Memori dan Operasi Primitif<br/>

#### 1. Create List
#### 2. Alokasi
#### 3. Dealokasi
#### 4. Pengecekan List (isEmpty)

### D. Operasi Penambahan Elemen (Insert)<br/>

#### 1. Insert First
#### 2. Inserrt Last
#### 3. Insert After

### E. Operasi Penghapusan Elemen (Delete)<br/>

#### 1. Delete First
#### 2. Delete Last
#### 3. Dealokasi/Delete Elemen

### F. Oprasi Lainnya<br/>

#### 1. View(printInfo)
#### 2. Update

## Guided 

### 1. List

```H
// hear guard digunakan untuk mencegah file header yg sama
// di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked list, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

// semua function & prosedur yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif
```
```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true;
    } else {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List){
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if(isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```
```C++
#include "list.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "231102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "231102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Program ini adalah implementasi struktur data *Singly Linked List* berbasis C++ untuk mengelola data mahasiswa secara dinamis yang mencakup file header `list.h` untuk mendeklarasikan struktur data dan purwarupa fungsi, file implementasi `list.cpp` yang berisi kode manajemen memori serta operasi penambahan dan penghapusan node, serta file utama `main.cpp` yang mengeksekusi seluruh alur program untuk memproses dan menampilkan data mahasiswa.

## Unguided 

### 1. (Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”)

```H
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif // SINGLYLIST_H_INCLUDED
```
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
        cout << "List kosong" << endl;
        return;
    }
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) {
            cout << " ";
        }
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else {
        P = L.First;
        L.First = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First->next == Nil) {
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
    } else {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.First;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    cout << "- List Berhasil Terhapus -" << endl;
}
```
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1](https://github.com/Hazell3/1090825000056_Andhika-Nur-Pratama_Smstr3/blob/main/Pertemuan4_Modul4/Unguided/Singlylist/Output%20Soal%201.png)

Singly Linked List merupakan struktur data dinamis yang terdiri dari kumpulan node yang saling terhubung menggunakan pointer. Setiap node memiliki dua bagian, yaitu `info` untuk menyimpan data dan `next` untuk menyimpan alamat node berikutnya. Pada praktikum Unguided 1, Singly Linked List diimplementasikan menggunakan bahasa C++ melalui tiga file, yaitu `Singlylist.h` sebagai tempat deklarasi struktur data dan prosedur, `Singlylist.cpp` sebagai tempat implementasi prosedur, serta `main.cpp` sebagai program utama. Prosedur `createList()` digunakan untuk menginisialisasi list kosong, `alokasi()` untuk membuat node baru, `dealokasi()` untuk membebaskan memori node, `insertFirst()` untuk menambahkan node pada bagian awal list, dan `printInfo()` untuk menampilkan seluruh data. Karena proses penyisipan dilakukan pada bagian awal, urutan data yang dimasukkan akan terbalik sehingga menghasilkan linked list `9 → 12 → 8 → 0 → 2`.

### 2. (Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().)
```H
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
int nbList(List L);
void deleteList(List &L);

#endif // SINGLYLIST_H_INCLUDED
```
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    if (P == Nil) {
        cout << "List kosong" << endl;
        return;
    }
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) {
            cout << " ";
        }
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else {
        P = L.First;
        L.First = P->next;
        P->next = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.First == Nil) {
        P = Nil;
    } else if (L.First->next == Nil) {
        P = L.First;
        L.First = Nil;
    } else {
        address Q = L.First;
        while (Q->next->next != Nil) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = Nil;
    }
}

void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
    } else {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.First;
    while (P != Nil) {
        jumlah++;
        P = P->next;
    }
    return jumlah;
}

void deleteList(List &L) {
    address P;
    while (L.First != Nil) {
        deleteFirst(L, P);
        dealokasi(P);
    }
    cout << "- List Berhasil Terhapus -" << endl;
}
```
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    address hapus;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);
    P2 = alokasi(0);
    insertFirst(L, P2);
    P3 = alokasi(8);
    insertFirst(L, P3);
    P4 = alokasi(12);
    insertFirst(L, P4);
    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L, hapus);
    dealokasi(hapus);

    deleteLast(L, hapus);
    dealokasi(hapus);

    deleteAfter(P4, hapus);
    dealokasi(hapus);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 2](https://github.com/Hazell3/1090825000056_Andhika-Nur-Pratama_Smstr3/blob/main/Pertemuan4_Modul4/Unguided/Singlylist/Output%20Soal%202.png)

Dilakukan operasi penghapusan node pada Singly Linked List yang telah dibuat sebelumnya. Prosedur deleteFirst() digunakan untuk menghapus node pertama, yaitu nilai 9, sehingga list menjadi 12 → 8 → 0 → 2. Selanjutnya, prosedur deleteLast() digunakan untuk menghapus node terakhir, yaitu nilai 2, sehingga list menjadi 12 → 8 → 0. Setelah itu, prosedur deleteAfter() digunakan untuk menghapus node yang berada setelah node pertama, yaitu nilai 8, sehingga tersisa list 12 → 0. Prosedur nbList() kemudian digunakan untuk menghitung jumlah node yang tersisa, yaitu sebanyak 2 node. Terakhir, prosedur deleteList() digunakan untuk menghapus seluruh node dalam linked list sehingga list kembali kosong dan jumlah node menjadi 0. Praktikum ini menunjukkan bahwa Singly Linked List dapat melakukan operasi penghapusan pada bagian awal, akhir, dan setelah node tertentu, serta menghitung jumlah node dan menghapus seluruh elemen dalam list.

## Kesimpulan
Kesimpulan dari praktikum Modul 4 tentang Linked List adalah bahwa Linked List merupakan struktur data linear yang bersifat dinamis dan terdiri dari node-node yang saling terhubung menggunakan pointer. Dalam implementasinya menggunakan bahasa C++, setiap node menyimpan data dan alamat node berikutnya sehingga memungkinkan penambahan dan penghapusan data secara fleksibel. Melalui praktikum ini, dipelajari penggunaan ADT untuk mendefinisikan struktur data serta berbagai prosedur, seperti `createList()` untuk membuat list kosong, `alokasi()` untuk membuat node baru, `insertFirst()`, `insertLast()`, dan `insertAfter()` untuk menambahkan node, serta `deleteFirst()`, `deleteLast()`, dan `deleteAfter()` untuk menghapus node pada posisi tertentu. Selain itu, prosedur `printInfo()` digunakan untuk menampilkan data, `nbList()` untuk menghitung jumlah node, dan `deleteList()` untuk menghapus seluruh node dalam list. Hasil praktikum menunjukkan bahwa penyisipan node pada bagian awal menyebabkan urutan data menjadi terbalik dari urutan pemasukan, sedangkan operasi penghapusan dapat mengurangi jumlah node sesuai dengan posisi yang ditentukan hingga seluruh list menjadi kosong. Dengan demikian, praktikum ini memberikan pemahaman mengenai konsep pointer, pengelolaan memori, serta operasi dasar Linked List dalam mengelola data secara dinamis.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
