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