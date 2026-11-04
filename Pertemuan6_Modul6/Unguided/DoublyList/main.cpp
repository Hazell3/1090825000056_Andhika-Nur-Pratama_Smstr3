#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    /* ===== Soal 1: input 4 data kendaraan ===== */
    for (int i = 0; i < 4; i++) {
        infotype x;
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);
    cout << endl;

    /* ===== Soal 2: mencari nomor polisi ===== */
    infotype cari;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cari.nopol;
    address F = findElm(L, cari);
    if (F != Nil) {
        cout << endl;
        cout << "Nomor Polisi : " << F->info.nopol << endl;
        cout << "Warna        : " << F->info.warna << endl;
        cout << "Tahun        : " << F->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }
    cout << endl;

    /* ===== Soal 3: menghapus nomor polisi ===== */
    infotype hapus;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapus.nopol;
    address target = findElm(L, hapus);
    if (target == Nil) {
        cout << "Data dengan nomor polisi " << hapus.nopol << " tidak ditemukan." << endl;
    } else {
        address P;
        if (target == L.First) {
            deleteFirst(L, P);
        } else if (target == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(target->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << hapus.nopol << " berhasil dihapus." << endl;
    }
    cout << endl << "DATA LIST 1" << endl << endl;
    printInfo(L);

    return 0;
}