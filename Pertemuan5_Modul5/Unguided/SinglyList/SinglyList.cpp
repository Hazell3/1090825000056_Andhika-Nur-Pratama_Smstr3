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