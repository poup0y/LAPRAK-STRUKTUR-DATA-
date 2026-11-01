
#include "stack.h"
#include <iostream>
#include <new>
using namespace std;

// Membuat stack kosong
void createStack(Stack &S) {
    S.Top = nullptr;
}

// Mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.Top == nullptr;
}

// Membuat node baru
address alokasi(int x) {
    address P = new (nothrow) ElmStack;

    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }

    return P;
}

// Menghapus node
void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

// Menambahkan data ke TOP
bool push(Stack &S, int x) {
    address P = alokasi(x);

    if (P == nullptr) {
        return false;
    }

    P->next = S.Top;
    S.Top = P;

    return true;
}

// Mengambil dan menghapus data TOP
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }

    address P = S.Top;

    x = P->info;
    S.Top = P->next;

    dealokasi(P);

    return true;
}

// Menampilkan isi stack dari TOP
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack masih kosong!" << endl;
        return;
    }

    address P = S.Top;

    cout << "Isi Stack (TOP ke bawah): ";

    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

// Menambahkan data secara terurut
bool pushAscending(Stack &S, int x) {
    Stack bantu;
    int data;

    createStack(bantu);

    // Memindahkan data yang lebih kecil dari x
    // ke stack bantu
    while (!isEmpty(S) && S.Top->info < x) {
        if (!pop(S, data)) {
            return false;
        }

        if (!push(bantu, data)) {
            push(S, data);

            while (!isEmpty(bantu)) {
                pop(bantu, data);
                push(S, data);
            }

            return false;
        }
    }

    // Memasukkan data baru
    if (!push(S, x)) {
        while (!isEmpty(bantu)) {
            pop(bantu, data);
            push(S, data);
        }

        return false;
    }

    // Mengembalikan data dari stack bantu
    while (!isEmpty(bantu)) {
        pop(bantu, data);

        if (!push(S, data)) {
            // Mengembalikan data jika alokasi gagal
            push(bantu, data);

            while (!isEmpty(bantu)) {
                pop(bantu, data);
                push(S, data);
            }

            return false;
        }
    }

    return true;
}

// Menghapus seluruh node
void clearStack(Stack &S) {
    int data;

    while (!isEmpty(S)) {
        pop(S, data);
    }

    S.Top = nullptr;
}
