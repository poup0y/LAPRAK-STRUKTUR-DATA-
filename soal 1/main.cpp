
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    int pilihan, angka;

    createStack(S);

    do {
        cout << "\n===== MENU STACK ARRAY =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan Stack" << endl;
        cout << "4. Balik Stack" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "Masukkan angka: ";
                cin >> angka;

                if (push(S, angka)) {
                    cout << "Data berhasil ditambahkan!" << endl;
                } else {
                    cout << "Stack penuh! Data tidak dapat ditambahkan." << endl;
                }
                break;

            case 2:
                if (pop(S, angka)) {
                    cout << "Data yang di-Pop: " << angka << endl;
                } else {
                    cout << "Stack kosong! Tidak ada data yang dapat diambil." << endl;
                }
                break;

            case 3:
                printInfo(S);
                break;

            case 4:
                balikStack(S);
                cout << "Isi Stack berhasil dibalik!" << endl;
                printInfo(S);
                break;

            case 5:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 5);

    return 0;
}
