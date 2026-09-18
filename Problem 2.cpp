#include <iostream>
#include <string>

using namespace std;

string enkripsiAlien(string pesan) {
    if (pesan.empty()) return "";

    string hasil = "";
    
    // Huruf pertama tidak mengalami perubahan
    hasil += pesan[0];

    // Proses untuk huruf kedua dan seterusnya
    for (int i = 1; i < pesan.length(); i++) {
        // Menentukan nilai pergeseran dari huruf SEBELUMNYA pada pesan asli
        int shift = pesan[i-1] - 'A' + 1;

        // Mendapatkan posisi huruf SAAT INI (0-25) untuk mempermudah perhitungan modulo
        int posisi_sekarang = pesan[i] - 'A';

        // Menghitung posisi baru dengan menambahkan nilai shift
        // Modulo 26 (% 26) memastikan perhitungan kembali ke A jika lewat Z
        int posisi_baru = (posisi_sekarang + shift) % 26;

        // Mengubah kembali posisi angka (0-25) menjadi huruf ('A'-'Z')
        hasil += (char)(posisi_baru + 'A');
    }

    return hasil;
}

int main() {
    string pesan;
    cout << "Masukkan pesan asli (KAPITAL): ";
    cin >> pesan;

    string pesan_sandi = enkripsiAlien(pesan);

    cout << "Pesan sandi: " << pesan_sandi << endl;

    return 0;
}