#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    system ("cls"); 
    char kode[11], keluar[5]; 
    cout << "Masukkan kode parkir digital (10 digit): ";
    cin >> kode;
    cout << "Masukkan jam keluar (format HHMM): ";
    cin >> keluar; 
    
    // Mengonversi karakter ke angka (int) dengan trik ASCII (- '0')
    int jenis = (kode[0]-'0')*10 + (kode[1]-'0');
    int jamMasuk = (kode[2]-'0')*10 + (kode[3]-'0');
    int menitMasuk = (kode[4]-'0')*10 + (kode[5]-'0'); 
   
    // Mengonversi string input "HHMM" menjadi angka jam dan menit terpisah
    int jamKeluar = (keluar[0]-'0')*10 + (keluar[1]-'0');
    int menitKeluar = (keluar[2]-'0')*10 + (keluar[3]-'0');
    
    // Hitung durasi (pembulatan ke atas)
    int durasi = ((jamKeluar*60 + menitKeluar) - (jamMasuk*60 + menitMasuk)+59) / 60;

    // Hitung biaya parkir berdasarkan kendaraan
    string namaJenis; 
    int hargaAwal, hargaBerikut; 

    if (jenis == 10) { 
        namaJenis = "Mobil"; 
        hargaAwal = 5000;
        hargaBerikut = 3000;}  
    else if (jenis == 20) {
        namaJenis = "Motor"; 
        hargaAwal = 3000;
        hargaBerikut = 2000;} 
    else if (jenis == 30) {
        namaJenis = "Bus"; 
        hargaAwal = 10000;
        hargaBerikut = 7000;} 
    else { 
        namaJenis = "TIDAK VALID";
        hargaAwal = 0;
        hargaBerikut = 0;} 

    int biaya = (durasi <= 0) ? 0 : hargaAwal + (durasi - 1) * hargaBerikut;
    
    // Output
    cout << "\n--- Ringkasan Parkir ---\n";
    cout << "Jenis kendaraan: " << namaJenis << endl;
    cout << "Waktu masuk: " << setw(2) << setfill('0') << jamMasuk << ":" << setw(2) << setfill('0') << menitMasuk << endl;
    cout << "Waktu keluar: " << setw(2) << setfill('0') << jamKeluar << ":" << setw(2) << setfill('0') << menitKeluar << endl;
    cout << "Durasi parkir: " << durasi << " jam" << endl;
    cout << "Lokasi parkir: " << kode[6] << kode[7] << kode[8] << kode[9] << endl;
    cout << "Total biaya: Rp " << biaya << endl;
    return 0;
}

/*
ALGORITMA PENYELESAIAN:
1. Program meminta pengguna memasukkan 10 digit kode parkir dan waktu keluar (HHMM).
2. Program mengekstraksi informasi dari kode parkir:
   - Digit ke-1 dan ke-2 menentukan jenis kendaraan.
   - Digit ke-3 dan ke-4 menentukan jam masuk.
   - Digit ke-5 dan ke-6 menentukan menit masuk.
   - Digit ke-7 sampai ke-10 menentukan identitas lokasi parkir.
3. Program mengonversi input waktu keluar menjadi jam dan menit yang terpisah.
4. Menghitung durasi parkir dengan cara:
   - Mengonversi semua waktu (masuk dan keluar) ke dalam satuan menit.
   - Menghitung selisih menit.
   - Membagi selisih dengan 60 dan melakukan pembulatan ke atas untuk mendapatkan total jam.
5. Menentukan tarif berdasarkan jenis kendaraan yang didapat dari kode:
   - Kode 10 (Mobil): Rp 5.000 (jam pertama), Rp 3.000 (jam berikutnya).
   - Kode 20 (Motor): Rp 3.000 (jam pertama), Rp 2.000 (jam berikutnya).
   - Kode 30 (Bus): Rp 10.000 (jam pertama), Rp 7.000 (jam berikutnya).
6. Menghitung total biaya berdasarkan durasi parkir.
7. Menampilkan ringkasan parkir yang mencakup jenis kendaraan, waktu masuk/keluar, durasi parkir, lokasi parkir, dan total biaya.
*/