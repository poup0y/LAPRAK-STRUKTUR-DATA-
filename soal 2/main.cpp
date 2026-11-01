
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    int pilihan, angka;

    createStack(S);

    do {
        cout << "\n===== MENU STACK POINTER =====" << endl;
        cout << "1. Tambah Terurut" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan Stack" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "Masukkan angka: ";
                cin >> angka;

                if (pushAscending(S, angka)) {
                    cout << "Data berhasil ditambahkan secara terurut!" << endl;
                } else {
                    cout << "Penambahan data gagal!" << endl;
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
                clearStack(S);
                cout << "Seluruh node berhasil dihapus." << endl;
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 4);

    return 0;
}
