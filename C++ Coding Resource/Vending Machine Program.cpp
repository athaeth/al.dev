#include <iostream>
#include <string>
#include <cstdlib> // Diperlukan untuk system("CLS")
using namespace std;

// Struktur data untuk menyimpan data user
class User {
  public:  
    string nama;
    string id;   
};

// Struktur data untuk menyimpan nota pembelian
class Nota {
   public: 
    string nama;             
    string id;               
    string detailPembelian[100]; 
    int jumlahItem[100];   
    int hargaItem[100];    
    int totalHarga;  
    int totalItem;        
};

// Fungsi untuk menampilkan daftar snack
void tampilkanDaftarSnack(const string snack[], const int hargaSnack[], int jumlahSnack) {
    cout << "\nDaftar Snack:\n";
    for (int i = 0; i < jumlahSnack; i++) {
        cout << " " << i + 1 << ". " << snack[i] << " - IDR " << hargaSnack[i] << endl;
    }
}

// Fungsi untuk menampilkan daftar minuman
void tampilkanDaftarMinuman(const string minuman[], const int hargaMinuman[], int jumlahMinuman) {
    cout << "\nDaftar Minuman:\n";
    for (int i = 0; i < jumlahMinuman; i++) {
        cout << " " << i + 1 << ". " << minuman[i] << " - IDR " << hargaMinuman[i] << endl;
    }
}

// Fungsi untuk mencetak nota pembelian
void cetakNota(const Nota &nota) {
    cout << "\n=== Bukti Pembelian ===\n";
    cout << "Nama: " << nota.nama << endl;
    cout << "ID: " << nota.id << endl;
    cout << "Detail Pembelian:\n";
    for (int i = 0; i < nota.totalItem; i++) {
        cout << "- " << nota.detailPembelian[i] << " x" 
             << nota.jumlahItem[i] << " = IDR " 
             << nota.hargaItem[i] * nota.jumlahItem[i] << endl;
    }
    cout << "Total Harga: IDR " << nota.totalHarga << endl << endl;
}

// Fungsi utama
int main() {
    // Daftar snack dan harganya
    string snack[10] = {"Lays", "Qtela", "Chitato", "Good Time", "Better", 
                        "Beng-beng", "Nabati", "SilverQueen", "Oreo", "Oishi Pillow"};
    int hargaSnack[10] = {20000, 16000, 12000, 8000, 8000, 15000, 5000, 18000, 13000, 12000};

    // Daftar minuman dan harganya
    string minuman[10] = {"Es Teh", "Mizone", "Ultra Milk", "Teh Botol Sosro", "Aqua", 
                          "Milo", "Fanta", "Good Day", "Yakult", "Cimory"};
    int hargaMinuman[10] = {3000, 8000, 6000, 8000, 5000, 9000, 7000, 5000, 10000, 10000};

    // Array untuk menyimpan data pengguna dan nota pembelian
    User users[100];
    Nota invoice[100];
    int totalUser = 0;
    int totalNota = 0;

    while (true) {
        // Membersihkan layar untuk tampilan menu utama
        system("CLS");
        cout << "\n===================================\n";
        cout << " Selamat Datang di Vending Machine\n";
        cout << "===================================\n";
        cout << "1. Register User\n";
        cout << "2. Login User\n";
        cout << "3. Keluar\n";
        cout << "Pilihan : ";
        int menu;
        cin >> menu;

        if (menu == 1) { // Menu Registrasi User
            system("CLS"); // Membersihkan layar sebelum registrasi
            if (totalUser >= 100) {
                cout << "Jumlah maksimal user telah tercapai.\n";
                continue;
            }
            User newUser;
            cout << "\n=== Silahkan Register ===";
            cout << "\nMasukkan Nama: ";
            cin.ignore();
            getline(cin, newUser.nama);
            cout << "Masukkan ID (3 digit): ";
            cin >> newUser.id;

            if (newUser.id.length() != 3 || newUser.id < "001" || newUser.id > "999") {
                cout << "ID tidak valid. Pastikan ID terdiri dari 3 digit.\n";
                continue;
            }

            users[totalUser++] = newUser;
            cout << "\nRegistrasi berhasil! Anda dapat login sekarang.\n\n";

        } else if (menu == 2) { // Menu Login User
            system("CLS"); // Membersihkan layar sebelum login
            string nama, id;
            bool loginSuccess = false;
            cout << "\n=== Silahkan Login ===";
            cout << "\nMasukkan Nama: ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukkan ID (3 digit): ";
            cin >> id;

            // Cek apakah user terdaftar
            for (int i = 0; i < totalUser; i++) {
                if (users[i].nama == nama && users[i].id == id) {
                    loginSuccess = true;
                    break;
                }
            }

            if (!loginSuccess) {
                cout << "Login gagal. Pastikan nama dan ID telah terdaftar.\n";
                continue;
            }

            // Menu setelah login
            while (true) {
                system("CLS"); // Membersihkan layar sebelum masuk ke menu vending machine
                cout << "\n=== Menu Vending Machine ===\n";
                cout << "1. Beli Snack dan Minuman\n";
                cout << "2. Lihat Bukti Pembelian\n";
                cout << "3. Keluar\n";
                cout << "Pilihan: ";
                int pilihanMenu;
                cin >> pilihanMenu;

                if (pilihanMenu == 1) { // Pembelian Snack/Minuman
                    Nota notaBaru;
                    notaBaru.nama = nama;
                    notaBaru.id = id;
                    notaBaru.totalHarga = 0;
                    notaBaru.totalItem = 0;

                    while (true) {
                        system("CLS"); // Membersihkan layar sebelum memilih item
                        cout << "\n\n=== Pilih Item ===\n";
                        cout << "1. Snack\n";
                        cout << "2. Minuman\n";
                        cout << "3. Selesai\n";
                        cout << "Pilihan: ";
                        int pilih;
                        cin >> pilih;

                        if (pilih == 1) {
                            tampilkanDaftarSnack(snack, hargaSnack, 10);
                            cout << "Pilih snack (1-10): ";
                            int pilihanItem, jumlahItem;
                            cin >> pilihanItem;
                            cout << "Jumlah: ";
                            cin >> jumlahItem;

                            notaBaru.detailPembelian[notaBaru.totalItem] = snack[pilihanItem - 1];
                            notaBaru.jumlahItem[notaBaru.totalItem] = jumlahItem;
                            notaBaru.hargaItem[notaBaru.totalItem] = hargaSnack[pilihanItem - 1];
                            notaBaru.totalHarga += hargaSnack[pilihanItem - 1] * jumlahItem;
                            notaBaru.totalItem++;

                        } else if (pilih == 2) {
                            tampilkanDaftarMinuman(minuman, hargaMinuman, 10);
                            cout << "Pilih minuman (1-10): ";
                            int pilihanItem, jumlahItem;
                            cin >> pilihanItem;
                            cout << "Jumlah: ";
                            cin >> jumlahItem;

                            notaBaru.detailPembelian[notaBaru.totalItem] = minuman[pilihanItem - 1];
                            notaBaru.jumlahItem[notaBaru.totalItem] = jumlahItem;
                            notaBaru.hargaItem[notaBaru.totalItem] = hargaMinuman[pilihanItem - 1];
                            notaBaru.totalHarga += hargaMinuman[pilihanItem - 1] * jumlahItem;
                            notaBaru.totalItem++;
                        }

                        // Tawaran menambah pesanan
                        cout << "\nApakah Anda ingin menambah pesanan? (y/n): ";
                        string tambahPesanan;
                        cin >> tambahPesanan;
                        if (tambahPesanan == "n") {
                            break; // Keluar dari loop pembelian
                        }
                    }

                    // Pembayaran
                    if (notaBaru.totalHarga > 0) {
                        cout << "Total Harga: IDR " << notaBaru.totalHarga << endl;
                        cout << "Masukkan jumlah uang: ";
                        int pembayaran;
                        cin >> pembayaran;

                        if (pembayaran >= notaBaru.totalHarga) {
                            cout << "Pembayaran berhasil! Kembalian: IDR " << pembayaran - notaBaru.totalHarga << endl;
                            invoice[totalNota++] = notaBaru;
                        } else {
                            cout << "Uang tidak cukup. Pesanan dibatalkan.\n";
                        }
                    } else {
                        cout << "Anda belum membeli apa pun.\n";
                    }

                } else if (pilihanMenu == 2) { // Lihat Bukti Pembelian
                    system("CLS");
                    bool adaNota = false;
                    for (int i = 0; i < totalNota; i++) {
                        if (invoice[i].nama == nama && invoice[i].id == id) {
                            cetakNota(invoice[i]);
                            adaNota = true;
                        }
                    }

                    if (!adaNota) {
                        cout << "Anda belum memiliki pembelian.\n";
                    }
                    system("pause"); // Menahan layar untuk melihat nota

                } else if (pilihanMenu == 3) { // Logout
                    cout << "Logout berhasil.\n";
                    break;
                } else {
                    cout << "Pilihan tidak valid.\n";
                }
            }

        } else if (menu == 3) { // Keluar dari program
            cout << "Terima kasih telah menggunakan vending machine.\n";
            break;
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}