#include "stack.h"

int isEmpty(Stack S) {
    if (S.Top == 0) {
        return 1;   // kosong
    } else {
        return 0;   // tidak kosong
    }
}

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype X) {
    if (S.Top < 10) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = X;
    } else {
        cout << "Stack penuh, tidak dapat ditambahkan" << endl;
    }
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S) == 1) {
        cout << "Stack kosong, tidak ada data yang bisa diambil" << endl;
    } else {
        X = S.info[S.Top - 1];
        S.Top = S.Top - 1;
    }
}

void viewStack(Stack S) {
    if (isEmpty(S) == 1) {
        cout << "Stack kosong" << endl;
    } else {
        cout << "Isi Stack (dari TOP):" << endl;
        for (int i = S.Top; i >= 1; i--) {
            cout << i << ", " << S.info[i - 1].nim << " - "
                 << S.info[i - 1].nama << endl;
        }
    }
}