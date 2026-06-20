#include <iostream>
#include <string>

using namespace std;

// Di C++, jika fungsi ditulis di atas main(), kita tidak butuh prototipe fungsi lagi.

// ==========================================
// 1. MODUL PENGGUNA (USER)
// ==========================================
void menuPengguna() {
    int pilihan;
    bool diMenuUser = true;

    // Variabel untuk menampung input simulasi dari user
    string platNomor, cariData;
    int bulanKeterlambatan;

    while (diMenuUser) {
        system("clear || cls"); // Bersihkan layar terminal
        cout << "====================================\n";
        cout << "   Selamat Datang di PajakKu!       \n";
        cout << "====================================\n";
        cout << "1. Data Kendaraan\n";
        cout << "2. Pembayaran Pajak\n";
        cout << "3. Perhitungan Denda\n";
        cout << "4. Riwayat Pembayaran\n";
        cout << "5. Pencarian Data\n";
        cout << "6. Logout / Keluar\n";
        cout << "------------------------------------\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        if (pilihan == 1) {
            system("clear || cls");
            cout << "[ MENU - DATA KENDARAAN ]\n\n";
            cout << "Berikut kendaraan aktif Anda:\n";
            cout << "- Honda Vario (L 1234 ABC) - Status: Siap Bayar\n";
            cout << "- Toyota Avanza (B 9999 XYZ) - Status: Lunas\n\n";
            
            system("pause");
        } 
        else if (pilihan == 2) {
            system("clear || cls");
            cout << "[ MENU - PEMBAYARAN PAJAK ]\n\n";
            cout << "Masukkan Plat Nomor Kendaraan: ";
            cin >> platNomor; // Menerima input teks plat nomor
            
            cout << "\nMemproses data " << platNomor << "...\n";
            cout << "Pembayaran Pajak sebesar Rp 350.000 Berhasil!\n\n";
            
            system("pause");
        } 
        else if (pilihan == 3) {
            system("clear || cls");
            cout << "[ MENU - PERHITUNGAN DENDA ]\n\n";
            cout << "Berapa bulan keterlambatan bayar pajak? : ";
            cin >> bulanKeterlambatan; // Menerima input angka
            
            // Rumus simulasi denda sederhana (misal per bulan Rp 50.000)
            int totalDenda = bulanKeterlambatan * 50000;
            cout << "Total estimasi denda Anda: Rp " << totalDenda << "\n\n";
            
            system("pause");
        } 
        else if (pilihan == 4) {
            system("clear || cls");
            cout << "[ MENU - RIWAYAT PEMBAYARAN ]\n\n";
            cout << "Log Transaksi Terakhir:\n";
            cout << "1. 10-02-2026 | L 1234 ABC | Rp 350.000 | SUKSES\n";
            cout << "2. 15-05-2025 | B 9999 XYZ | Rp 2.100.000 | SUKSES\n\n";
            
            system("pause");
        } 
        else if (pilihan == 5) {
            system("clear || cls");
            cout << "[ MENU - PENCARIAN DATA ]\n\n";
            cout << "Masukkan Plat Nomor yang ingin dicari: ";
            cin >> cariData;
            
            cout << "\nHasil pencarian untuk '" << cariData << "':\n";
            cout << "Data ditemukan! Masa berlaku STNK hingga 2030.\n\n";
            
            system("pause");
        } 
        else if (pilihan == 6) {
            cout << "\nLogout berhasil. Kembali ke halaman utama...\n";
            system("pause");
            diMenuUser = false; // Keluar dari loop user, otomatis kembali ke menu login
        } 
        else {
            cout << "\nPilihan salah! Silakan masukkan angka dari 1 sampai 6.\n\n";
            system("pause");
        }
    }
}

// ==========================================
// 2. MODUL UTAMA (LOGIN & DAFTAR)
// ==========================================
void menuUtama() {
    int pilihanUtama;
    bool programBerjalan = true;
    
    // Variabel untuk menampung data login/daftar
    string username, password, role;

    while (programBerjalan) {
        system("clear || cls");
        cout << "====================================\n";
        cout << "          PAJAKKU - UTAMA           \n";
        cout << "====================================\n";
        cout << "1. DAFTAR   -> Registrasi akun baru\n";
        cout << "2. MASUK    -> Login ke sistem\n";
        cout << "3. EXIT     -> Keluar program\n";
        cout << "------------------------------------\n";
        cout << "Pilih menu (1-3): ";
        cin >> pilihanUtama;

        if (pilihanUtama == 1) {
            system("clear || cls");
            cout << "[ DAFTAR AKUN BARU ]\n\n";
            cout << "Buat Username baru: ";
            cin >> username;
            cout << "Buat Password baru: ";
            cin >> password;
            
            cout << "\nAkun dengan nama '" << username << "' berhasil terdaftar!\n\n";
            system("pause");
        } 
        else if (pilihanUtama == 2) {
            system("clear || cls");
            cout << "[ MASUK KE SISTEM ]\n\n";
            cout << "Username : ";
            cin >> username;
            cout << "Password : ";
            cin >> password;

            // Simulasi hak akses berdasarkan input string role
            cout << "Masuk sebagai (admin/user): ";
            cin >> role;

            if (role == "user" || role == "USER") {
                // Jika login sebagai user, lempar ke modul menuPengguna() milikmu
                menuPengguna(); 
            } 
            else if (role == "admin" || role == "ADMIN") {
                cout << "\n[INFO] Fitur Admin milik kelompok lain belum diintegrasikan.\n\n";
                system("pause");
            } 
            else {
                cout << "\nRole tidak valid! Ketik 'user' atau 'admin'.\n\n";
                system("pause");
            }
        } 
        else if (pilihanUtama == 3) {
            cout << "\nTerima kasih telah menggunakan PajakKu. Sampai jumpa!\n";
            programBerjalan = false; // Menghentikan seluruh program
        } 
        else {
            cout << "\nPilihan tidak valid! Silakan pilih angka 1-3.\n\n";
            system("pause");
        }
    }
}

// ==========================================
// 3. GERBANG EKSEKUSI PROGRAM
// ==========================================
int main() {
    // Membuka menu awal (Login/Daftar) saat program pertama kali dirun
    menuUtama();
    return 0;
}