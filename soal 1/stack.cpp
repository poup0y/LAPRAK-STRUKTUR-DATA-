
#include "stack.h"
#include <iostream>
using namespace std;

// Membuat stack baru
void createStack(Stack &S) {
    S.Top = 0;
}

// Mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.Top == 0;
}

// Mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.Top == MAX;
}

// Menambahkan data ke dalam stack
bool push(Stack &S, int x) {
    if (isFull(S)) {
        return false;
    }

    S.Top++;
    S.info[S.Top] = x;

    return true;
}

// Mengambil data paling atas
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }

    x = S.info[S.Top];
    S.Top--;

    return true;
}

// Menampilkan isi stack dari TOP
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack masih kosong!" << endl;
        return;
    }

    cout << "Isi Stack (TOP ke bawah): ";

    for (int i = S.Top; i >= 1; i--) {
        cout << S.info[i] << " ";
    }

    cout << endl;
}

// Membalik seluruh isi stack
void balikStack(Stack &S) {
    Stack bantu;
    int x;

    createStack(bantu);

    while (!isEmpty(S)) {
        pop(S, x);
        push(bantu, x);
    }

    while (!isEmpty(bantu)) {
        pop(bantu, x);
        push(S, x);
    }
}
