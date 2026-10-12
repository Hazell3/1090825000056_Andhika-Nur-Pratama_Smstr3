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