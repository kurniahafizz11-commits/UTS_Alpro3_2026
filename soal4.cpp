#include <iostream>
#include <string>
using namespace std;

int main() {
    system ("cls"); 
    int N; 
    string S; 
    
    // Membaca input
    cout<<"Jumlah babak dalam satu pertandingan: ";
    cin >> N; 
    cout<<"Hasil pemenang setiap babak: ";
    cin >> S; 
    
    // validasi panjang string
    if (S.length() != N) { 
        cout << "Error: Panjang string tidak sesuai dengan jumlah babak!" << endl;
        return 1; 
    }
    // validasi karakter input
    for (int i = 0; i < N; i++) { 
        char c = S[i]; 
        if (c != 'A' && c != 'B' && c != 'C') { 
            cout << "Error: Karakter '" << c << "' pada babak ke-" << i+1  
                 << " tidak valid! Harus A, B, atau C." << endl; 
            return 1; 
        }
    }
    int poinA = 0, poinB = 0; 
    int streakA = 0, streakB = 0; 
    
    // Memproses setiap babak
    for (int i = 0; i < N; i++) {
        char hasil = S[i]; 
        
        // Aturan poin dasar
        if (hasil == 'A') { 
            poinA += 3;
            streakA++;
            streakB = 0; 
        } 
        else if (hasil == 'B') {
            poinB += 3;
            streakB++;
            streakA = 0; 
        } 
        else if (hasil == 'C') {
            poinA += 1;
            poinB += 1;
            streakA = 0; 
            streakB = 0; 
        }
        
        // Cek bonus untuk 3 kemenangan berturut-turut
        if (streakA == 3) {
            poinA += 2;
            streakA = 0; 
        } 
        else if (streakB == 3) {
            poinB += 2;
            streakB = 0;
        }
    }
    
    // Output poin
    cout << "Poin A: " << poinA << endl;
    cout << "Poin B: " << poinB << endl;

    // Menentukan output pemenang atau seri
    if (poinA > poinB) { 
        cout << "Pemenangnya adalah Pemain A" << endl; }
    else if (poinB > poinA) {
        cout << "Pemenangnya adalah Pemain B" << endl; } 
    else {
        cout << "Hasil pertandingan Seri!" << endl; }
    return 0;
}

/*
ALGORITMA PENYELESAIAN:
1. Program meminta input jumlah babak (N) dan urutan hasil pemenang (string S).
2. Program melakukan validasi:
   - Memastikan panjang string (hasil pemenang setiap babak) sesuai dengan jumlah babak.
   - Memastikan karakter hanya berisi 'A' (Pemenang A), 'B' (Pemenang B), atau 'C' (Seri).
3. Inisialisasi variabel poin dan variabel 'streak' (kemenangan beruntun) untuk masing-masing pemain dengan nilai 0.
4. Program melakukan iterasi (looping) untuk memproses hasil setiap babak:
   - Jika 'A' menang: Tambah 3 poin ke Pemain A, streak bertambah 1 untuk pemain A, dan reset streak B ke 0.
   - Jika 'B' menang: Tambah 3 poin ke Pemain B, streak bertambah 1 untuk pemain B, dan reset streak A ke 0.
   - Jika 'C' (Seri): Tambah 1 poin ke masing-masing pemain dan reset kedua streak ke 0.
5. Mengecek bonus kemenangan beruntun: Jika salah satu pemain mencapai streak 3 kali menang berturut-turut, maka diberikan tambahan 2 poin bonus dan streak di-reset ke 0.
6. Program menampilkan total poin akhir yang didapat Pemain A dan Pemain B.
7. Program membandingkan poin akhir untuk menentukan dan menampilkan pemenang pertandingan (A, B, atau Seri).
*/