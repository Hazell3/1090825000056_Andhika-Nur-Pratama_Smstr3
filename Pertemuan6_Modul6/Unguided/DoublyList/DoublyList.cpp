#include "Doublylist.h"

/* membuat list kosong */
void CreateList(List &L) {
    L.First = Nil;
    L.Last = Nil;
}

/* membuat elemen baru berisi x */
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

/* menghapus elemen dari memori */
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

/* menampilkan isi list dari elemen terakhir ke pertama (iterasi mundur) */
void printInfo(List L) {
    address P = L.Last;
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        P = P->prev;
    }
}

/* menambah elemen di akhir list */
void insertLast(List &L, address P) {
    if (L.First == Nil) {          // list kosong
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        (L.Last)->next = P;
        L.Last = P;
    }
}

/* mencari elemen berdasarkan nomor polisi, mengembalikan Nil jika tidak ada */
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

/* menghapus elemen pertama, hasilnya disimpan di P */
void deleteFirst(List &L, address &P) {
    P = L.First;
    if (P == Nil) return;
    if (L.First == L.Last) {       // hanya 1 elemen
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.First = (L.First)->next;
        (L.First)->prev = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}

/* menghapus elemen terakhir, hasilnya disimpan di P */
void deleteLast(List &L, address &P) {
    P = L.Last;
    if (P == Nil) return;
    if (L.First == L.Last) {       // hanya 1 elemen
        L.First = Nil;
        L.Last = Nil;
    } else {
        L.Last = (L.Last)->prev;
        (L.Last)->next = Nil;
    }
    P->next = Nil;
    P->prev = Nil;
}

/* menghapus elemen setelah Prec, hasilnya disimpan di P */
void deleteAfter(address Prec, address &P) {
    P = Nil;
    if (Prec == Nil || Prec->next == Nil) return;
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != Nil) {
        (P->next)->prev = Prec;
    }
    P->next = Nil;
    P->prev = Nil;
}