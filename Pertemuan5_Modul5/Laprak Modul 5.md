# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Andhika Nur Pratama - 109082500056</p>

## Dasar Teori
<div align ="justify">Linked list atau senarai berantai merupakan struktur data linear yang terdiri dari kumpulan elemen berupa node yang saling terhubung menggunakan pointer dan tidak harus disimpan secara berurutan dalam memori [1]. Pada struktur Singly Linked List, setiap node memiliki dua bagian, yaitu data untuk menyimpan informasi dan pointer next untuk menunjuk ke node berikutnya, sedangkan node terakhir menunjuk ke NULL [1]. Operasi pada Singly Linked List meliputi insertion untuk menambahkan node, deletion untuk menghapus node, searching untuk mencari data, dan traversal untuk mengunjungi setiap node [2]. Struktur data ini mendukung pengelolaan memori secara dinamis dan memungkinkan penambahan atau penghapusan elemen tanpa harus memindahkan seluruh elemen seperti pada array [1].<div/>

### A. Searching<br/>
...
#### 1. Insert After
#### 2. Delete After
#### 3. Update

## Guided 

### 1.  List Buah

```H
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

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
Program ini merupakan implementasi Singly Linked List dalam bahasa C++ untuk mengelola data buah yang terdiri dari nama, jumlah, dan harga. Program menyediakan berbagai operasi, mulai dari membuat list kosong, menambahkan node di awal, tengah, dan akhir, menampilkan serta menghitung jumlah node, memperbarui data buah, mencari data berdasarkan nama, alamat node, dan rentang harga, hingga menghapus node tertentu maupun seluruh isi list. Melalui program ini, kita dapat memahami cara kerja linked list dalam mengelola data secara dinamis menggunakan pointer dan alokasi memori.

## Unguided 

###    [1](Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”)
###    [2](Carilah elemen dengan info 8 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address)
###    [3](Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31))

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
    address first;
};

// ===== Soal 2 =====
void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

// ===== Soal 3 =====
address findElm(List L, infotype x);

// ===== Soal 4 =====
int sumInfo(List L);

#endif // SINGLYLIST_H_INCLUDED
```
```C++
#include "Singlylist.h"

// Membuat list kosong
void CreateList(List &L) {
    L.first = Nil;
}

// Membuat elemen baru berisi x
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

// Mengembalikan memori elemen P
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Menampilkan semua info di list
void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Menaruh elemen P di awal list
void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

// Mencari elemen dengan info = x
// Mengembalikan alamat elemen jika ketemu, Nil jika tidak
address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

// Menjumlahkan semua info di list
int sumInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total += P->info;
        P = P->next;
    }
    return total;
}
```
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);

    // ===== Soal 2 =====
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

    // ===== Soal 3 : cari elemen dengan info 8 =====
    address hasil = findElm(L, 8);
    if (hasil != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    // ===== Soal 4 : total info seluruh elemen =====
    cout << "Total info dari kelima elemen adalah " << sumInfo(L) << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/Hazell3/1090825000056_Andhika-Nur-Pratama_Smstr3/blob/main/Pertemuan5_Modul5/Unguided/SinglyList/Output%20SinglyList.png)

[1]Dimulai dari pembuatan singly linked list, yaitu rantai node yang saling tersambung lewat pointer next, di mana setiap node menyimpan info sebagai data dan next sebagai alamat node berikutnya. Agar rantai ini bisa dipakai, kita perlu menyiapkan list kosong lebih dulu dengan CreateList, yang mengisi first dengan Nil. Setelah list siap, alokasi membuat node baru di memori dan mengisinya dengan data, lalu node tersebut dipasang ke list oleh insertFirst, yang menyambungkan next node baru ke node pertama lama sebelum menjadikannya first yang baru. Karena setiap node baru selalu dipasang di depan, data yang dimasukkan 2, 0, 8, 12, 9 akan tercetak terbalik saat printInfo menelusurinya, sehingga hasilnya 9 12 8 0 2. Terakhir, jika sebuah node sudah tidak dipakai, dealokasi mengembalikan memorinya ke sistem agar tidak terbuang.

[2]Setelah list terisi, kita bisa mencari data tertentu di dalamnya, dan pekerjaan ini dilakukan oleh findElm. Fungsi ini menelusuri list dari node pertama sambil membandingkan info setiap node dengan nilai yang dicari. Jika nilainya sama, fungsi langsung mengembalikan alamat node tersebut, tetapi jika penelusuran sudah sampai Nil tanpa menemukan apa pun, fungsi mengembalikan Nil. Untuk mencari angka 8, penelusuran melewati node 9 dan 12 terlebih dahulu, lalu berhenti di node 8, sehingga program menampilkan “8 ditemukan dalam list”. Alamat yang dikembalikan inilah yang membuat findElm berguna, sebab hasilnya bisa langsung dipakai untuk operasi lain seperti insertAfter dan delAfter.

[3]Soal terakhir memakai cara penelusuran yang sama dengan printInfo dan findElm, tetapi tujuannya berbeda, yaitu menghitung jumlah semua data. Untuk itu, sumInfo menyiapkan variabel total yang bernilai 0, lalu menambahkan info dari setiap node yang dilewati selama berjalan dari first sampai Nil. Prosesnya berjalan 0+9=9, kemudian 9+12=21, 21+8=29, 29+0=29, dan terakhir 29+2=31, sehingga program menampilkan “Total info dari kelima elemen adalah 31”. Karena fungsi ini harus mengunjungi semua node satu per satu, waktu kerjanya O(n), sama seperti printInfo.

## Kesimpulan
<div align ="justify">Singly linked list adalah kumpulan node yang tersambung lewat pointer next dan hanya bisa diakses melalui first, sehingga hampir semua operasinya dilakukan dengan menelusuri node satu per satu dari first sampai Nil. Pola penelusuran inilah yang dipakai di seluruh latihan: insertFirst menaruh node di depan list sehingga data 2, 0, 8, 12, 9 tercetak terbalik menjadi 9 12 8 0 2, findElm mencari node dan mengembalikan alamatnya (atau Nil jika tidak ada) yang kemudian bisa dipakai untuk operasi seperti insertAfter dan delAfter, dan sumInfo menjumlahkan semua data hingga mendapat 31. Dari latihan ini terlihat bahwa penambahan di depan cepat (O(1)) sedangkan pencarian dan penjumlahan lebih lambat (O(n)), bahwa parameter & dipakai saat fungsi mengubah list dan tidak dipakai saat hanya membaca, serta bahwa memori node dari alokasi perlu dikembalikan dengan dealokasi.<div/>

## Referensi
[1] Acharjya, P. P., Koley, S., & Barman, S. (2020). Analysis of the Complexity of Various Linked Lists. Turkish Journal of Computer and Mathematics Education, 11(2), 886–895. https://doi.org/10.17762/turcomat.v11i2.11883 
<br>[2] Saeed, M., & Gulati, M. (2013). Linked Implementation of List. International Journal of Science, Technology & Management, 2(11)
<br>...
