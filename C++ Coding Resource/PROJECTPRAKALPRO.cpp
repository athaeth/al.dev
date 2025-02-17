#include <iostream>
#include <string>

using namespace std;

struct Cucian {
    int id;
    string nama_pelanggan;
    string jenis_pakaian;
    float berat;
    float total_harga;
};
void tampilkanData(Cucian laundry[], int jumlah) {
    if (jumlah == 0) {
        cout << "\nBelum ada data cucian.\n";
        return;
    }
    
    cout << "\n=== Data Cucian ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "ID: " << laundry[i].id << endl;
        cout << "Nama Pelanggan: " << laundry[i].nama_pelanggan << endl;
        cout << "Jenis Pakaian: " << laundry[i].jenis_pakaian << endl;
        cout << "Berat: " << laundry[i].berat << " kg" << endl;
        cout << "Total Harga: Rp " << laundry[i].total_harga << endl;
        cout << "-------------------------" << endl;
    }
}
void inputData(Cucian laundry[], int &jumlah) {
    int tambah;
    cout << "Masukkan jumlah cucian yang ingin ditambahkan: ";
    cin >> tambah;
    cin.ignore();

    for (int i = jumlah; i < jumlah + tambah; i++) {
        cout << "\nData Cucian ke-" << i + 1 << endl;
        cout << "Masukkan ID Cucian: ";
        cin >> laundry[i].id;
        cin.ignore();

        cout << "Masukkan Nama Pelanggan: ";
        getline(cin, laundry[i].nama_pelanggan);

        cout << "Masukkan Jenis Pakaian: ";
        getline(cin, laundry[i].jenis_pakaian);

        do {
            cout << "Masukkan Berat Pakaian (kg): ";
            cin >> laundry[i].berat;
            cin.ignore();

            if (laundry[i].berat >= 1 && laundry[i].berat <= 10) {
                laundry[i].total_harga = laundry[i].berat * 10000; 
            } else {
                cout << "\nMaaf, kami hanya bisa melayani cucian dengan berat 1 - 10 Kg saja.\n";
            }
        } while (laundry[i].berat < 1 || laundry[i].berat > 10);
    }

    jumlah += tambah; 
    tampilkanData(laundry, jumlah);
}

int main() {
    Cucian laundry[100]; 
    int jumlah = 0;
    int pilihan;

    do {
        cout << "\n=== MENU LAUNDRY CIHUY ===\n";
        cout << "1. Input Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                inputData(laundry, jumlah);
                break;
            case 2:
                tampilkanData(laundry, jumlah);
                break;
            case 3:
                cout << "Terima kasih telah menggunakan Laundry Cihuy!\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    } while (pilihan != 3);

    return 0;
}
