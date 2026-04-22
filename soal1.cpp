#include <iostream>
#include <string> 
using namespace std;

int main() {
    string nomor; 
    cout << "Masukkan nomor kartu digital: ";
    cin >> nomor; 

    int n = nomor.length(); 
    string tipe = "TIDAK DIKENAL"; 
    // Cek Tipe Kartu
    if (n == 14 && nomor.substr(0, 2) == "65") tipe = "NUSANTARA";
    else if (n == 16 && (nomor.substr(0, 2) == "77" || nomor.substr(0, 2) == "78")) tipe = "GARUDA";
    else if (n == 15 && nomor.substr(0, 2) == "91") tipe = "MERDEKA";

    // Algoritma Validasi
    int total = 0; 
    for (int i = 0; i < n; i++) { 
        int digit = nomor[i] - '0';
        if ((n - i) % 2 == 0) { 
            digit *= 2;
            if (digit > 9) digit = (digit / 10) + (digit % 10); 
        }
        total += digit; 
    }    

    // Output pada Test Case
    cout << "Tipe kartu: " << tipe << endl; 
    if (tipe != "TIDAK DIKENAL" && total % 10 == 0) {
        cout << "Nomor kartu VALID." << endl;
    } else {
        cout << "Nomor kartu TIDAK VALID." << endl; 
    }

    return 0;
}

/*
ALGORITMA PENYELESAIAN:
1. Program menerima input berupa deretan angka dalam bentuk string (nomor kartu digital).
2. Program mengidentifikasi tipe kartu berdasarkan panjang karakter dan dua digit pertama:
   - Jika panjang 14 dan diawali '65', maka tipe "NUSANTARA".
   - Jika panjang 16 dan diawali '77' atau '78', maka tipe "GARUDA".
   - Jika panjang 15 dan diawali '91', maka tipe "MERDEKA".
   - Selain itu, tipe dianggap "TIDAK DIKENAL".
3. Program melakukan validasi nomor kartu menggunakan modifikasi algoritma Luhn:
   - Setiap digit diperiksa satu per satu.
   - Digit pada posisi genap (dihitung dari belakang) dikalikan dua.
   - Jika hasil perkalian lebih dari 9, kedua digit hasilnya dijumlahkan.
   - Semua digit (baik yang sudah dimodifikasi maupun yang asli) dijumlahkan ke variabel 'total'.
4. Program memeriksa keabsahan akhir:
   - Kartu dinyatakan VALID jika tipenya dikenali DAN hasil total penjumlahan habis dibagi 10.
5. Program menampilkan tipe kartu dan status validitasnya ke layar.
*/