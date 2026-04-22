#include <iostream>
#include <string> 
using namespace std;

int main() {
    system ("cls");
    string kode; 
    
    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;
    
    // Validasi panjang
    if (kode.length() != 8) { 
        cout << "Kode harus 8 digit!" << endl; 
        return 1; 
    }
    
    // Ambil komponen manual (ekstrak data dari kode)
    int hari = (kode[0] - '0') * 10 + (kode[1] - '0'); 
    int member = (kode[2] - '0') * 10 + (kode[3] - '0');
    int belanja = 0; 
    for (int i = 4; i < 8; i++) { 
        belanja = belanja * 10 + (kode[i] - '0'); 
    }
    belanja *= 100000; 
    
    // Validasi kode
    if (hari < 1 || hari > 3 || member < 1 || member > 3) { 
        cout << "Kode hari atau member tidak valid!" << endl; 
        return 1; 
    }
    
    // Tabel poin (2 dimensi)
    int poinTable[3][3] = { 
        {1, 2, 3},  // Hari Kerja
        {2, 3, 5},  // Akhir Pekan
        {3, 5, 7}   // Libur Nasional
    };
    
    // Hitung poin
    int poin = (belanja / 100000) * poinTable[hari-1][member-1];
    
    // Nama
    string namaHari[] = {"Hari Kerja", "Akhir Pekan", "Hari Libur Nasional"};
    string jenisMember[] = {"biasa", "silver", "gold"};
   
    
    // Output
    cout << "Jenis Hari: " << namaHari[hari-1] << endl; 
    cout << "Jenis Pelanggan: " << jenisMember[member-1] << endl; 
    cout << "Jumlah Belanja: Rp " << belanja << endl; 
    cout << "Total Poin: " << poin << endl;
    
    return 0;
}

/*
ALGORITMA PENYELESAIAN:
1. Program meminta input kode transaksi sebanyak 8 digit dari pengguna.
2. Program memvalidasi panjang kode; jika tidak sama dengan 8 digit, program berhenti.
3. Program mengekstraksi data dari string kode:
   - Digit ke-1 dan ke-2 dikonversi menjadi angka untuk menentukan 'Hari'.
   - Digit ke-3 dan ke-4 dikonversi menjadi angka untuk menentukan 'Jenis Member'.
   - Digit ke-5 sampai ke-8 dikonversi menjadi angka dasar belanja, lalu dikalikan 100.000.
4. Program melakukan validasi rentang angka untuk variabel hari (1-3) dan member (1-3).
5. Program menentukan pengali poin menggunakan matriks (tabel 2 dimensi) berdasarkan kombinasi hari dan jenis member.
6. Menghitung total poin dengan rumus: (Total Belanja / 100.000) dikali nilai pengali dari tabel poin.
7. Program menampilkan ringkasan transaksi yang meliputi jenis hari, jenis pelanggan, jumlah belanja, dan total poin yang didapatkan.
*/